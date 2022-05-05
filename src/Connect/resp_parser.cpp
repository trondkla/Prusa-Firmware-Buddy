#include "resp_parser.h"

/*
 * The parsing automata. Generated by python scripts.
 */
#include <http_resp_automaton.h>

using automata::Event;
using automata::ExecutionControl;
using con::parser::response::Names;

namespace {

const automata::Automaton http_response(con::parser::response::paths, con::parser::response::transitions, con::parser::response::states);

}

namespace con::parser {

ResponseParser::ResponseParser()
    : Execution(&http_response) {
}

ExecutionControl ResponseParser::event(Event event) {
    switch (event.entering_state) {
    case Names::StatusCode:
        status_code = 10 * status_code + (event.payload - '0');
        return ExecutionControl::Continue;
    case Names::Body:
        done = true;
        // Yes, really don't stop. Eath the \n too!
        return ExecutionControl::Continue;
    case Names::ContentLength:
        if (!content_length.has_value()) {
            content_length = 0;
        }
        *content_length = 10 * *content_length + (event.payload - '0');
        return ExecutionControl::Continue;
    }

    return ExecutionControl::Continue;
}

}
