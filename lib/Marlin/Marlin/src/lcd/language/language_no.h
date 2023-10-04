/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Norwegian (bokmål)
 *
 * LCD Menu Messages
 * See also http://marlinfw.org/docs/development/lcd_language.html
 *
 */

#define DISPLAY_CHARSET_ISO10646_1

namespace Language_no {
  using namespace Language_en; // Inherit undefined strings from English

  constexpr uint8_t    CHARSIZE                            = 2;
  PROGMEM Language_Str LANGUAGE                            = _UxGT("Norwegian");

  PROGMEM Language_Str WELCOME_MSG                         = MACHINE_NAME _UxGT(" er klar");
  PROGMEM Language_Str MSG_YES                             = _UxGT("JA");
  PROGMEM Language_Str MSG_NO                              = _UxGT("NEI");
  PROGMEM Language_Str MSG_BACK                            = _UxGT("Tilbake");
  PROGMEM Language_Str MSG_MEDIA_ABORTING                  = _UxGT("Avbryter...");
  PROGMEM Language_Str MSG_MEDIA_INSERTED                  = _UxGT("Kort satt inn");
  PROGMEM Language_Str MSG_MEDIA_REMOVED                   = _UxGT("Kort fjernet");
  PROGMEM Language_Str MSG_MEDIA_RELEASED                  = _UxGT("Media sluppet");
  PROGMEM Language_Str MSG_MEDIA_WAITING                   = _UxGT("Venter på media");
  PROGMEM Language_Str MSG_MEDIA_READ_ERROR                = _UxGT("Media lesefeil");
  PROGMEM Language_Str MSG_MEDIA_USB_REMOVED               = _UxGT("USB-enhet fjernet");
  PROGMEM Language_Str MSG_MEDIA_USB_FAILED                = _UxGT("USB start feilet");
  PROGMEM Language_Str MSG_LCD_ENDSTOPS                    = _UxGT("Endstops"); // Max length 8 characters
  PROGMEM Language_Str MSG_LCD_SOFT_ENDSTOPS               = _UxGT("Soft Endstops");
  PROGMEM Language_Str MSG_MAIN                            = _UxGT("Menu");
  PROGMEM Language_Str MSG_ADVANCED_SETTINGS               = _UxGT("Avanserte innstillinger");
  PROGMEM Language_Str MSG_CONFIGURATION                   = _UxGT("Konfigurasjon");
  PROGMEM Language_Str MSG_AUTOSTART                       = _UxGT("Autostart");
  PROGMEM Language_Str MSG_DISABLE_STEPPERS                = _UxGT("Slå av alle steppere");
  PROGMEM Language_Str MSG_DEBUG_MENU                      = _UxGT("Feilsøk Menu");
  PROGMEM Language_Str MSG_PROGRESS_BAR_TEST               = _UxGT("Fremdriftslinjetest");
  PROGMEM Language_Str MSG_AUTO_HOME                       = _UxGT("Auto hjem"); // G28
  PROGMEM Language_Str MSG_AUTO_HOME_X                     = _UxGT("Hjem X");
  PROGMEM Language_Str MSG_AUTO_HOME_Y                     = _UxGT("Hjem Y");
  PROGMEM Language_Str MSG_AUTO_HOME_Z                     = _UxGT("Hjem Z");
  PROGMEM Language_Str MSG_AUTO_Z_ALIGN                    = _UxGT("Auto Z-juster");
  PROGMEM Language_Str MSG_LEVEL_BED_HOMING                = _UxGT("Heiming XYZ");
  PROGMEM Language_Str MSG_LEVEL_BED_WAITING               = _UxGT("Klikk når du er klar");
  PROGMEM Language_Str MSG_LEVEL_BED_NEXT_POINT            = _UxGT("Neste punkt");
  PROGMEM Language_Str MSG_LEVEL_BED_DONE                  = _UxGT("Bed level er ferdig!");
  PROGMEM Language_Str MSG_Z_FADE_HEIGHT                   = _UxGT("Fade Height");
  PROGMEM Language_Str MSG_SET_HOME_OFFSETS                = _UxGT("Sett hjem forskyvning");
  PROGMEM Language_Str MSG_HOME_OFFSETS_APPLIED            = _UxGT("Forskyvninger brukt");
  PROGMEM Language_Str MSG_SET_ORIGIN                      = _UxGT("Sett origin");
  PROGMEM Language_Str MSG_PREHEAT_1                       = _UxGT("Forvarm ") PREHEAT_1_LABEL;
  PROGMEM Language_Str MSG_PREHEAT_1_H0                    = _UxGT("Forvarm ") PREHEAT_1_LABEL " " LCD_STR_N0;
  PROGMEM Language_Str MSG_PREHEAT_1_H1                    = _UxGT("Forvarm ") PREHEAT_1_LABEL " " LCD_STR_N1;
  PROGMEM Language_Str MSG_PREHEAT_1_H2                    = _UxGT("Forvarm ") PREHEAT_1_LABEL " " LCD_STR_N2;
  PROGMEM Language_Str MSG_PREHEAT_1_H3                    = _UxGT("Forvarm ") PREHEAT_1_LABEL " " LCD_STR_N3;
  PROGMEM Language_Str MSG_PREHEAT_1_H4                    = _UxGT("Forvarm ") PREHEAT_1_LABEL " " LCD_STR_N4;
  PROGMEM Language_Str MSG_PREHEAT_1_H5                    = _UxGT("Forvarm ") PREHEAT_1_LABEL " " LCD_STR_N5;
  PROGMEM Language_Str MSG_PREHEAT_1_END                   = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" end")
  PROGMEM Language_Str MSG_PREHEAT_1_END_E0                = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" end ") LCD_STR_N0;
  PROGMEM Language_Str MSG_PREHEAT_1_END_E1                = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" end ") LCD_STR_N1;
  PROGMEM Language_Str MSG_PREHEAT_1_END_E2                = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" end ") LCD_STR_N2;
  PROGMEM Language_Str MSG_PREHEAT_1_END_E3                = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" end ") LCD_STR_N3;
  PROGMEM Language_Str MSG_PREHEAT_1_END_E4                = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" end ") LCD_STR_N4;
  PROGMEM Language_Str MSG_PREHEAT_1_END_E5                = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" end ") LCD_STR_N5;
  PROGMEM Language_Str MSG_PREHEAT_1_ALL                   = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" Alle");
  PROGMEM Language_Str MSG_PREHEAT_1_BEDONLY               = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" Seng");
  PROGMEM Language_Str MSG_PREHEAT_1_SETTINGS              = _UxGT("Forvarm ") PREHEAT_1_LABEL _UxGT(" conf");
  PROGMEM Language_Str MSG_PREHEAT_2                       = _UxGT("Forvarm ") PREHEAT_2_LABEL;
  PROGMEM Language_Str MSG_PREHEAT_2_H0                    = _UxGT("Forvarm ") PREHEAT_2_LABEL " " LCD_STR_N0;
  PROGMEM Language_Str MSG_PREHEAT_2_H1                    = _UxGT("Forvarm ") PREHEAT_2_LABEL " " LCD_STR_N1;
  PROGMEM Language_Str MSG_PREHEAT_2_H2                    = _UxGT("Forvarm ") PREHEAT_2_LABEL " " LCD_STR_N2;
  PROGMEM Language_Str MSG_PREHEAT_2_H3                    = _UxGT("Forvarm ") PREHEAT_2_LABEL " " LCD_STR_N3;
  PROGMEM Language_Str MSG_PREHEAT_2_H4                    = _UxGT("Forvarm ") PREHEAT_2_LABEL " " LCD_STR_N4;
  PROGMEM Language_Str MSG_PREHEAT_2_H5                    = _UxGT("Forvarm ") PREHEAT_2_LABEL " " LCD_STR_N5;
  PROGMEM Language_Str MSG_PREHEAT_2_END                   = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" end")
  PROGMEM Language_Str MSG_PREHEAT_2_END_E0                = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" end ") LCD_STR_N0;
  PROGMEM Language_Str MSG_PREHEAT_2_END_E1                = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" end ") LCD_STR_N1;
  PROGMEM Language_Str MSG_PREHEAT_2_END_E2                = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" end ") LCD_STR_N2;
  PROGMEM Language_Str MSG_PREHEAT_2_END_E3                = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" end ") LCD_STR_N3;
  PROGMEM Language_Str MSG_PREHEAT_2_END_E4                = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" end ") LCD_STR_N4;
  PROGMEM Language_Str MSG_PREHEAT_2_END_E5                = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" end ") LCD_STR_N5;
  PROGMEM Language_Str MSG_PREHEAT_2_ALL                   = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" Alle");
  PROGMEM Language_Str MSG_PREHEAT_2_BEDONLY               = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" Seng");
  PROGMEM Language_Str MSG_PREHEAT_2_SETTINGS              = _UxGT("Forvarm ") PREHEAT_2_LABEL _UxGT(" conf");
  PROGMEM Language_Str MSG_PREHEAT_CUSTOM                  = _UxGT("Forvarm Tilpass");
  PROGMEM Language_Str MSG_COOLDOWN                        = _UxGT("Avkjøl");
  PROGMEM Language_Str MSG_LASER_MENU                      = _UxGT("Laserkontroll");
  PROGMEM Language_Str MSG_LASER_OFF                       = _UxGT("Laser av");
  PROGMEM Language_Str MSG_LASER_ON                        = _UxGT("Laser på");
  PROGMEM Language_Str MSG_LASER_POWER                     = _UxGT("Laser strøm");
  PROGMEM Language_Str MSG_SPINDLE_MENU                    = _UxGT("Spindelkontroll");
  PROGMEM Language_Str MSG_SPINDLE_OFF                     = _UxGT("Spindel av");
  PROGMEM Language_Str MSG_SPINDLE_ON                      = _UxGT("Spindel på");
  PROGMEM Language_Str MSG_SPINDLE_POWER                   = _UxGT("Spindel strøm");
  PROGMEM Language_Str MSG_SPINDLE_REVERSE                 = _UxGT("Spindel reverser");
  PROGMEM Language_Str MSG_SWITCH_PS_ON                    = _UxGT("Slå på strøm");
  PROGMEM Language_Str MSG_SWITCH_PS_OFF                   = _UxGT("Slå av strøm");
  PROGMEM Language_Str MSG_EXTRUDE                         = _UxGT("Ekstruder");
  PROGMEM Language_Str MSG_RETRACT                         = _UxGT("Trekk tilbake");
  PROGMEM Language_Str MSG_MOVE_AXIS                       = _UxGT("Flytt akser");
  PROGMEM Language_Str MSG_BED_LEVELING                    = _UxGT("Utjevn seng");
  PROGMEM Language_Str MSG_LEVEL_BED                       = _UxGT("Utjevn seng");

  PROGMEM Language_Str MSG_LEVEL_CORNERS                   = _UxGT("Planer hjørner");
  PROGMEM Language_Str MSG_NEXT_CORNER                     = _UxGT("Neste hjørne");
  PROGMEM Language_Str MSG_MESH_EDITOR                     = _UxGT("Mesh Editor");
  PROGMEM Language_Str MSG_EDIT_MESH                       = _UxGT("Endre Mesh");
  PROGMEM Language_Str MSG_EDITING_STOPPED                 = _UxGT("Mesh endring stoppet");
  PROGMEM Language_Str MSG_PROBING_MESH                    = _UxGT("Probe punkt");
  PROGMEM Language_Str MSG_MESH_X                          = _UxGT("Indeks X");
  PROGMEM Language_Str MSG_MESH_Y                          = _UxGT("Indeks Y");
  PROGMEM Language_Str MSG_MESH_EDIT_Z                     = _UxGT("Z-verdi");
  PROGMEM Language_Str MSG_USER_MENU                       = _UxGT("Egendef. Kommandoer");
  PROGMEM Language_Str MSG_M48_TEST                        = _UxGT("M48 Probe Test");
  PROGMEM Language_Str MSG_M48_POINT                       = _UxGT("M48 Punkt");
  PROGMEM Language_Str MSG_M48_DEVIATION                   = _UxGT("Avvik");
  PROGMEM Language_Str MSG_IDEX_MENU                       = _UxGT("IDEX Modus");
  PROGMEM Language_Str MSG_OFFSETS_MENU                    = _UxGT("Utstyrforskyn.");
  PROGMEM Language_Str MSG_IDEX_MODE_AUTOPARK              = _UxGT("Auto-Parker");
  PROGMEM Language_Str MSG_IDEX_MODE_DUPLICATE             = _UxGT("Duplisering");
  PROGMEM Language_Str MSG_IDEX_MODE_MIRRORED_COPY         = _UxGT("Speilvendt kopi");
  PROGMEM Language_Str MSG_IDEX_MODE_FULL_CTRL             = _UxGT("Full kontroll");
  PROGMEM Language_Str MSG_X_OFFSET                        = _UxGT("2. Dyse X");
  PROGMEM Language_Str MSG_Y_OFFSET                        = _UxGT("2. Dyse Y");
  PROGMEM Language_Str MSG_Z_OFFSET                        = _UxGT("2. Dyse Z");
  PROGMEM Language_Str MSG_UBL_DOING_G29                   = _UxGT("Utfører G29");
  PROGMEM Language_Str MSG_UBL_TOOLS                       = _UxGT("UBL utstyr");
  PROGMEM Language_Str MSG_UBL_LEVEL_BED                   = _UxGT("Unified Bed Leveling");
  PROGMEM Language_Str MSG_LCD_TILTING_MESH                = _UxGT("Vippepunkt");
  PROGMEM Language_Str MSG_UBL_MANUAL_MESH                 = _UxGT("Manuelt bygd Mesh");
  PROGMEM Language_Str MSG_UBL_BC_INSERT                   = _UxGT("Plasser avstandsstykke & mål"); // TODO Place shim & measure
  PROGMEM Language_Str MSG_UBL_BC_INSERT2                  = _UxGT("Mål");
  PROGMEM Language_Str MSG_UBL_BC_REMOVE                   = _UxGT("Fjern og mål seng");
  PROGMEM Language_Str MSG_UBL_MOVING_TO_NEXT              = _UxGT("Gå til neste");
  PROGMEM Language_Str MSG_UBL_ACTIVATE_MESH               = _UxGT("Aktiver UBL");
  PROGMEM Language_Str MSG_UBL_DEACTIVATE_MESH             = _UxGT("Deaktiver UBL");
  PROGMEM Language_Str MSG_UBL_SET_TEMP_BED                = _UxGT("Sengetemp.");
  PROGMEM Language_Str MSG_UBL_BED_TEMP_CUSTOM             = _UxGT("Sengetemp.");
  PROGMEM Language_Str MSG_UBL_SET_TEMP_HOTEND             = _UxGT("Hotend temp.");
  PROGMEM Language_Str MSG_UBL_HOTEND_TEMP_CUSTOM          = _UxGT("Hotend temp.");
  PROGMEM Language_Str MSG_UBL_MESH_EDIT                   = _UxGT("Mesh endre");
  PROGMEM Language_Str MSG_UBL_EDIT_CUSTOM_MESH            = _UxGT("Endre tilpas. Mesh");
  PROGMEM Language_Str MSG_UBL_FINE_TUNE_MESH              = _UxGT("Fintilpasse Mesh");
  PROGMEM Language_Str MSG_UBL_DONE_EDITING_MESH           = _UxGT("Ferdig å endre Mesh");
  PROGMEM Language_Str MSG_UBL_BUILD_CUSTOM_MESH           = _UxGT("Bygg tilpasset Mesh");
  PROGMEM Language_Str MSG_UBL_BUILD_MESH_MENU             = _UxGT("Bygg Mesh");
  PROGMEM Language_Str MSG_UBL_BUILD_MESH_M1               = _UxGT("Bygg Mesh (") PREHEAT_1_LABEL _UxGT(")");
  PROGMEM Language_Str MSG_UBL_BUILD_MESH_M2               = _UxGT("Bygg Mesh (") PREHEAT_2_LABEL _UxGT(")");
  PROGMEM Language_Str MSG_UBL_BUILD_COLD_MESH             = _UxGT("Bygg kald Mesh");
  PROGMEM Language_Str MSG_UBL_MESH_HEIGHT_ADJUST          = _UxGT("Tilpass Mesh høyde");
  PROGMEM Language_Str MSG_UBL_MESH_HEIGHT_AMOUNT          = _UxGT("Høyde");
  PROGMEM Language_Str MSG_UBL_VALIDATE_MESH_MENU          = _UxGT("Valider Mesh");
  PROGMEM Language_Str MSG_UBL_VALIDATE_MESH_M1            = _UxGT("Valider Mesh (") PREHEAT_1_LABEL _UxGT(")");
  PROGMEM Language_Str MSG_UBL_VALIDATE_MESH_M2            = _UxGT("Valider Mesh (") PREHEAT_2_LABEL _UxGT(")");
  PROGMEM Language_Str MSG_UBL_VALIDATE_CUSTOM_MESH        = _UxGT("Valider tilpas. Mesh");
  PROGMEM Language_Str MSG_G26_HEATING_BED                 = _UxGT("G26 Varmer seng");
  PROGMEM Language_Str MSG_G26_HEATING_NOZZLE              = _UxGT("G26 Varmer dyse");
  PROGMEM Language_Str MSG_G26_MANUAL_PRIME                = _UxGT("Manuell priming...");
  PROGMEM Language_Str MSG_G26_FIXED_LENGTH                = _UxGT("Primer med fast lengde");
  PROGMEM Language_Str MSG_G26_PRIME_DONE                  = _UxGT("Ferdig å prime");
  PROGMEM Language_Str MSG_G26_CANCELED                    = _UxGT("G26 avbrutt");
  PROGMEM Language_Str MSG_G26_LEAVING                     = _UxGT("Forlater G26");
  PROGMEM Language_Str MSG_UBL_CONTINUE_MESH               = _UxGT("Fortsett senge-Mesh");
  PROGMEM Language_Str MSG_UBL_MESH_LEVELING               = _UxGT("Mesh utjevning");
  PROGMEM Language_Str MSG_UBL_3POINT_MESH_LEVELING        = _UxGT("3-punkts utjevning");
  PROGMEM Language_Str MSG_UBL_GRID_MESH_LEVELING          = _UxGT("Rutenett Mesh utjevn.");
  PROGMEM Language_Str MSG_UBL_MESH_LEVEL                  = _UxGT("Utjevn Mesh");
  PROGMEM Language_Str MSG_UBL_SIDE_POINTS                 = _UxGT("Sidepunkter");
  PROGMEM Language_Str MSG_UBL_MAP_TYPE                    = _UxGT("Karttype");
  PROGMEM Language_Str MSG_UBL_OUTPUT_MAP                  = _UxGT("Output Mesh Map"); // TODO
  PROGMEM Language_Str MSG_UBL_OUTPUT_MAP_HOST             = _UxGT("Output for Host"); // TODO
  PROGMEM Language_Str MSG_UBL_OUTPUT_MAP_CSV              = _UxGT("Output for CSV"); // TODO
  PROGMEM Language_Str MSG_UBL_OUTPUT_MAP_BACKUP           = _UxGT("Off Printer Backup"); // TODO
  PROGMEM Language_Str MSG_UBL_INFO_UBL                    = _UxGT("Output UBL Info"); // TODO
  PROGMEM Language_Str MSG_UBL_FILLIN_AMOUNT               = _UxGT("Innfyll mengde");
  PROGMEM Language_Str MSG_UBL_MANUAL_FILLIN               = _UxGT("Manuell innfyll");
  PROGMEM Language_Str MSG_UBL_SMART_FILLIN                = _UxGT("Smart innfyll");
  PROGMEM Language_Str MSG_UBL_FILLIN_MESH                 = _UxGT("Innfyll Mesh");
  PROGMEM Language_Str MSG_UBL_INVALIDATE_ALL              = _UxGT("Invalider alle");
  PROGMEM Language_Str MSG_UBL_INVALIDATE_CLOSEST          = _UxGT("Invalider nærmeste");
  PROGMEM Language_Str MSG_UBL_FINE_TUNE_ALL               = _UxGT("Finjuster alle");
  PROGMEM Language_Str MSG_UBL_FINE_TUNE_CLOSEST           = _UxGT("Finjuster nærmeste");
  PROGMEM Language_Str MSG_UBL_STORAGE_MESH_MENU           = _UxGT("Mesh lagring");
  PROGMEM Language_Str MSG_UBL_STORAGE_SLOT                = _UxGT("Lagringsspor");
  PROGMEM Language_Str MSG_UBL_LOAD_MESH                   = _UxGT("Last senge-Mesh");
  PROGMEM Language_Str MSG_UBL_SAVE_MESH                   = _UxGT("Lagre senge-Mesh");
  PROGMEM Language_Str MSG_MESH_LOADED                     = _UxGT("M117 Mesh %i Lastet");
  PROGMEM Language_Str MSG_MESH_SAVED                      = _UxGT("M117 Mesh %i Lagret");
  PROGMEM Language_Str MSG_UBL_NO_STORAGE                  = _UxGT("Ingen lagring");
  PROGMEM Language_Str MSG_UBL_SAVE_ERROR                  = _UxGT("Feil: UBL Lagre");
  PROGMEM Language_Str MSG_UBL_RESTORE_ERROR               = _UxGT("Feil: UBL gjen.opp.");
  PROGMEM Language_Str MSG_UBL_Z_OFFSET                    = _UxGT("Z-Forskyv.: ");
  PROGMEM Language_Str MSG_UBL_Z_OFFSET_STOPPED            = _UxGT("Z-Forskyv. stoppet");
  PROGMEM Language_Str MSG_UBL_STEP_BY_STEP_MENU           = _UxGT("Step-By-Step UBL");
  PROGMEM Language_Str MSG_UBL_1_BUILD_COLD_MESH           = _UxGT("1. Lag kald-Mesh");
  PROGMEM Language_Str MSG_UBL_2_SMART_FILLIN              = _UxGT("2. Smart innfyll");
  PROGMEM Language_Str MSG_UBL_3_VALIDATE_MESH_MENU        = _UxGT("3. Valider Mesh");
  PROGMEM Language_Str MSG_UBL_4_FINE_TUNE_ALL             = _UxGT("4. Finjuster alle");
  PROGMEM Language_Str MSG_UBL_5_VALIDATE_MESH_MENU        = _UxGT("5. Valider Mesh");
  PROGMEM Language_Str MSG_UBL_6_FINE_TUNE_ALL             = _UxGT("6. Finjuster alle");
  PROGMEM Language_Str MSG_UBL_7_SAVE_MESH                 = _UxGT("7. Lagre senge-Mesh");

  PROGMEM Language_Str MSG_LED_CONTROL                     = _UxGT("LED kontroller");
  PROGMEM Language_Str MSG_LEDS                            = _UxGT("Lys");
  PROGMEM Language_Str MSG_LED_PRESETS                     = _UxGT("Light Presets");
  PROGMEM Language_Str MSG_SET_LEDS_RED                    = _UxGT("Rød");
  PROGMEM Language_Str MSG_SET_LEDS_ORANGE                 = _UxGT("Oransj");
  PROGMEM Language_Str MSG_SET_LEDS_YELLOW                 = _UxGT("Gul");
  PROGMEM Language_Str MSG_SET_LEDS_GREEN                  = _UxGT("Grønn");
  PROGMEM Language_Str MSG_SET_LEDS_BLUE                   = _UxGT("Blå");
  PROGMEM Language_Str MSG_SET_LEDS_INDIGO                 = _UxGT("Indigo");
  PROGMEM Language_Str MSG_SET_LEDS_VIOLET                 = _UxGT("Fiolett");
  PROGMEM Language_Str MSG_SET_LEDS_WHITE                  = _UxGT("Hvit");
  PROGMEM Language_Str MSG_SET_LEDS_DEFAULT                = _UxGT("Standard");
  PROGMEM Language_Str MSG_CUSTOM_LEDS                     = _UxGT("Tilpassede lys");
  PROGMEM Language_Str MSG_INTENSITY_R                     = _UxGT("Rød intensivitet");
  PROGMEM Language_Str MSG_INTENSITY_G                     = _UxGT("Grønn intensivitet");
  PROGMEM Language_Str MSG_INTENSITY_B                     = _UxGT("Blå intensivitet");
  PROGMEM Language_Str MSG_INTENSITY_W                     = _UxGT("Hvit intensivitet");
  PROGMEM Language_Str MSG_LED_BRIGHTNESS                  = _UxGT("Lysstyrke");

  PROGMEM Language_Str MSG_MOVING                          = _UxGT("Flytter...");
  PROGMEM Language_Str MSG_FREE_XY                         = _UxGT("Fri XY");
  PROGMEM Language_Str MSG_MOVE_X                          = _UxGT("Flytt X");
  PROGMEM Language_Str MSG_MOVE_Y                          = _UxGT("Flytt Y");
  PROGMEM Language_Str MSG_MOVE_Z                          = _UxGT("Flytt Z");
  PROGMEM Language_Str MSG_MOVE_E                          = _UxGT("Extruder");  // TODO
  PROGMEM Language_Str MSG_MOVE_E0                         = _UxGT("Extruder ") LCD_STR_E0;  // TODO
  PROGMEM Language_Str MSG_MOVE_E1                         = _UxGT("Extruder ") LCD_STR_E1;  // TODO
  PROGMEM Language_Str MSG_MOVE_E2                         = _UxGT("Extruder ") LCD_STR_E2;  // TODO
  PROGMEM Language_Str MSG_MOVE_E3                         = _UxGT("Extruder ") LCD_STR_E3;  // TODO
  PROGMEM Language_Str MSG_MOVE_E4                         = _UxGT("Extruder ") LCD_STR_E4;  // TODO
  PROGMEM Language_Str MSG_MOVE_E5                         = _UxGT("Extruder ") LCD_STR_E5;  // TODO
  PROGMEM Language_Str MSG_HOTEND_TOO_COLD                 = _UxGT("Hotend too cold");  // TODO

  PROGMEM Language_Str MSG_MOVE_Z_DIST                     = _UxGT("Flytt %smm");
  PROGMEM Language_Str MSG_MOVE_01MM                       = _UxGT("Flytt 0.1mm");
  PROGMEM Language_Str MSG_MOVE_1MM                        = _UxGT("Flytt 1mm");
  PROGMEM Language_Str MSG_MOVE_10MM                       = _UxGT("Flytt 10mm");
  PROGMEM Language_Str MSG_SPEED                           = _UxGT("Hastighet");
  PROGMEM Language_Str MSG_BED_Z                           = _UxGT("Seng Z");
  PROGMEM Language_Str MSG_NOZZLE                          = _UxGT("Dyse");
  PROGMEM Language_Str MSG_NOZZLE_0                        = _UxGT("Dyse ") LCD_STR_N0;
  PROGMEM Language_Str MSG_NOZZLE_1                        = _UxGT("Dyse ") LCD_STR_N1;
  PROGMEM Language_Str MSG_NOZZLE_2                        = _UxGT("Dyse ") LCD_STR_N2;
  PROGMEM Language_Str MSG_NOZZLE_3                        = _UxGT("Dyse ") LCD_STR_N3;
  PROGMEM Language_Str MSG_NOZZLE_4                        = _UxGT("Dyse ") LCD_STR_N4;
  PROGMEM Language_Str MSG_NOZZLE_5                        = _UxGT("Dyse ") LCD_STR_N5;
  PROGMEM Language_Str MSG_BED                             = _UxGT("Seng");
  PROGMEM Language_Str MSG_CHAMBER                         = _UxGT("Enclosure"); // TODO
  PROGMEM Language_Str MSG_HEATBREAK                       = _UxGT("Heatbreak"); // TODO

  PROGMEM Language_Str MSG_FAN_SPEED                       = _UxGT("Viftehastighet");
  PROGMEM Language_Str MSG_FAN_SPEED_1                     = _UxGT("Viftehastighet 1");
  PROGMEM Language_Str MSG_FAN_SPEED_2                     = _UxGT("Viftehastighet 2");
  PROGMEM Language_Str MSG_FAN_SPEED_3                     = _UxGT("Viftehastighet 3");
  PROGMEM Language_Str MSG_EXTRA_FAN_SPEED                 = _UxGT("Extra Fan Speed"); // TODO
  PROGMEM Language_Str MSG_EXTRA_FAN_SPEED_1               = _UxGT("Extra Fan Speed 1"); // TODO
  PROGMEM Language_Str MSG_EXTRA_FAN_SPEED_2               = _UxGT("Extra Fan Speed 2"); // TODO
  PROGMEM Language_Str MSG_EXTRA_FAN_SPEED_3               = _UxGT("Extra Fan Speed 3"); // TODO
  PROGMEM Language_Str MSG_FLOW                            = _UxGT("Flow"); // TODO
  PROGMEM Language_Str MSG_FLOW_0                          = _UxGT("Flow ") LCD_STR_N0; // TODO
  PROGMEM Language_Str MSG_FLOW_1                          = _UxGT("Flow ") LCD_STR_N1; // TODO
  PROGMEM Language_Str MSG_FLOW_2                          = _UxGT("Flow ") LCD_STR_N2; // TODO
  PROGMEM Language_Str MSG_FLOW_3                          = _UxGT("Flow ") LCD_STR_N3; // TODO
  PROGMEM Language_Str MSG_FLOW_4                          = _UxGT("Flow ") LCD_STR_N4; // TODO
  PROGMEM Language_Str MSG_FLOW_5                          = _UxGT("Flow ") LCD_STR_N5; // TODO
  PROGMEM Language_Str MSG_CONTROL                         = _UxGT("Kontrol");
  PROGMEM Language_Str MSG_MIN                             = _UxGT(" \002 Min");
  PROGMEM Language_Str MSG_MAX                             = _UxGT(" \002 Max");
  PROGMEM Language_Str MSG_FACTOR                          = _UxGT(" \002 Fact");
  PROGMEM Language_Str MSG_AUTOTEMP                        = _UxGT("Autotemp");
  PROGMEM Language_Str MSG_LCD_ON                          = _UxGT("Til");
  PROGMEM Language_Str MSG_LCD_OFF                         = _UxGT("Fra");


  PROGMEM Language_Str MSG_AUTOTUNE_PID                    = _UxGT("PID Autotune"); // TODO
  PROGMEM Language_Str MSG_AUTOTUNE_PID_E0                 = _UxGT("PID Autotune ") LCD_STR_E0; // TODO
  PROGMEM Language_Str MSG_AUTOTUNE_PID_E1                 = _UxGT("PID Autotune ") LCD_STR_E1; // TODO
  PROGMEM Language_Str MSG_AUTOTUNE_PID_E2                 = _UxGT("PID Autotune ") LCD_STR_E2; // TODO
  PROGMEM Language_Str MSG_AUTOTUNE_PID_E3                 = _UxGT("PID Autotune ") LCD_STR_E3; // TODO
  PROGMEM Language_Str MSG_AUTOTUNE_PID_E4                 = _UxGT("PID Autotune ") LCD_STR_E4; // TODO
  PROGMEM Language_Str MSG_AUTOTUNE_PID_E5                 = _UxGT("PID Autotune ") LCD_STR_E5; // TODO
  PROGMEM Language_Str MSG_PID_P                           = _UxGT("PID-P"); // TODO
  PROGMEM Language_Str MSG_PID_P_E0                        = _UxGT("PID-P ") LCD_STR_E0; // TODO
  PROGMEM Language_Str MSG_PID_P_E1                        = _UxGT("PID-P ") LCD_STR_E1; // TODO
  PROGMEM Language_Str MSG_PID_P_E2                        = _UxGT("PID-P ") LCD_STR_E2; // TODO
  PROGMEM Language_Str MSG_PID_P_E3                        = _UxGT("PID-P ") LCD_STR_E3; // TODO
  PROGMEM Language_Str MSG_PID_P_E4                        = _UxGT("PID-P ") LCD_STR_E4; // TODO
  PROGMEM Language_Str MSG_PID_P_E5                        = _UxGT("PID-P ") LCD_STR_E5; // TODO
  PROGMEM Language_Str MSG_PID_I                           = _UxGT("PID-I"); // TODO
  PROGMEM Language_Str MSG_PID_I_E0                        = _UxGT("PID-I ") LCD_STR_E0; // TODO
  PROGMEM Language_Str MSG_PID_I_E1                        = _UxGT("PID-I ") LCD_STR_E1; // TODO
  PROGMEM Language_Str MSG_PID_I_E2                        = _UxGT("PID-I ") LCD_STR_E2; // TODO
  PROGMEM Language_Str MSG_PID_I_E3                        = _UxGT("PID-I ") LCD_STR_E3; // TODO
  PROGMEM Language_Str MSG_PID_I_E4                        = _UxGT("PID-I ") LCD_STR_E4; // TODO
  PROGMEM Language_Str MSG_PID_I_E5                        = _UxGT("PID-I ") LCD_STR_E5; // TODO
  PROGMEM Language_Str MSG_PID_D                           = _UxGT("PID-D"); // TODO
  PROGMEM Language_Str MSG_PID_D_E0                        = _UxGT("PID-D ") LCD_STR_E0; // TODO
  PROGMEM Language_Str MSG_PID_D_E1                        = _UxGT("PID-D ") LCD_STR_E1; // TODO
  PROGMEM Language_Str MSG_PID_D_E2                        = _UxGT("PID-D ") LCD_STR_E2; // TODO
  PROGMEM Language_Str MSG_PID_D_E3                        = _UxGT("PID-D ") LCD_STR_E3; // TODO
  PROGMEM Language_Str MSG_PID_D_E4                        = _UxGT("PID-D ") LCD_STR_E4; // TODO
  PROGMEM Language_Str MSG_PID_D_E5                        = _UxGT("PID-D ") LCD_STR_E5; // TODO
  PROGMEM Language_Str MSG_PID_C                           = _UxGT("PID-C"); // TODO
  PROGMEM Language_Str MSG_PID_C_E0                        = _UxGT("PID-C ") LCD_STR_E0; // TODO
  PROGMEM Language_Str MSG_PID_C_E1                        = _UxGT("PID-C ") LCD_STR_E1; // TODO
  PROGMEM Language_Str MSG_PID_C_E2                        = _UxGT("PID-C ") LCD_STR_E2; // TODO
  PROGMEM Language_Str MSG_PID_C_E3                        = _UxGT("PID-C ") LCD_STR_E3; // TODO
  PROGMEM Language_Str MSG_PID_C_E4                        = _UxGT("PID-C ") LCD_STR_E4; // TODO
  PROGMEM Language_Str MSG_PID_C_E5                        = _UxGT("PID-C ") LCD_STR_E5; // TODO

  PROGMEM Language_Str MSG_SELECT                          = _UxGT("Velg");
  PROGMEM Language_Str MSG_SELECT_E0                       = _UxGT("Velg ") LCD_STR_E0;
  PROGMEM Language_Str MSG_SELECT_E1                       = _UxGT("Velg ") LCD_STR_E1;
  PROGMEM Language_Str MSG_SELECT_E2                       = _UxGT("Velg ") LCD_STR_E2;
  PROGMEM Language_Str MSG_SELECT_E3                       = _UxGT("Velg ") LCD_STR_E3;
  PROGMEM Language_Str MSG_SELECT_E4                       = _UxGT("Velg ") LCD_STR_E4;
  PROGMEM Language_Str MSG_SELECT_E5                       = _UxGT("Velg ") LCD_STR_E5;


  PROGMEM Language_Str MSG_ACC                             = _UxGT("Accel"); // TODO
  PROGMEM Language_Str MSG_JERK                            = _UxGT("Jerk"); // TODO
  PROGMEM Language_Str MSG_VA_JERK                         = _UxGT("V") LCD_STR_A _UxGT("-Jerk"); // TODO
  PROGMEM Language_Str MSG_VB_JERK                         = _UxGT("V") LCD_STR_B _UxGT("-Jerk"); // TODO
  PROGMEM Language_Str MSG_VC_JERK                         = _UxGT("V") LCD_STR_C _UxGT("-Jerk"); // TODO
  PROGMEM Language_Str MSG_VE_JERK                         = _UxGT("Ve-Jerk"); // TODO
  PROGMEM Language_Str MSG_JUNCTION_DEVIATION              = _UxGT("Junction Dev"); // TODO
  PROGMEM Language_Str MSG_VELOCITY                        = _UxGT("Velocity"); // TODO
  PROGMEM Language_Str MSG_VMAX_A                          = _UxGT("Vmax ") LCD_STR_A; // TODO
  PROGMEM Language_Str MSG_VMAX_B                          = _UxGT("Vmax ") LCD_STR_B; // TODO
  PROGMEM Language_Str MSG_VMAX_C                          = _UxGT("Vmax ") LCD_STR_C; // TODO
  PROGMEM Language_Str MSG_VMAX_E                          = _UxGT("Vmax ") LCD_STR_E; // TODO
  PROGMEM Language_Str MSG_VMAX_E0                         = _UxGT("Vmax ") LCD_STR_E0; // TODO
  PROGMEM Language_Str MSG_VMAX_E1                         = _UxGT("Vmax ") LCD_STR_E1; // TODO
  PROGMEM Language_Str MSG_VMAX_E2                         = _UxGT("Vmax ") LCD_STR_E2; // TODO
  PROGMEM Language_Str MSG_VMAX_E3                         = _UxGT("Vmax ") LCD_STR_E3; // TODO
  PROGMEM Language_Str MSG_VMAX_E4                         = _UxGT("Vmax ") LCD_STR_E4; // TODO
  PROGMEM Language_Str MSG_VMAX_E5                         = _UxGT("Vmax ") LCD_STR_E5; // TODO
  PROGMEM Language_Str MSG_VMIN                            = _UxGT("Vmin"); // TODO
  PROGMEM Language_Str MSG_VTRAV_MIN                       = _UxGT("VTrav Min"); // TODO
  PROGMEM Language_Str MSG_ACCELERATION                    = _UxGT("Acceleration"); // TODO
  PROGMEM Language_Str MSG_AMAX_A                          = _UxGT("Amax ") LCD_STR_A; // TODO
  PROGMEM Language_Str MSG_AMAX_B                          = _UxGT("Amax ") LCD_STR_B; // TODO
  PROGMEM Language_Str MSG_AMAX_C                          = _UxGT("Amax ") LCD_STR_C; // TODO
  PROGMEM Language_Str MSG_AMAX_E                          = _UxGT("Amax ") LCD_STR_E; // TODO
  PROGMEM Language_Str MSG_AMAX_E0                         = _UxGT("Amax ") LCD_STR_E0; // TODO
  PROGMEM Language_Str MSG_AMAX_E1                         = _UxGT("Amax ") LCD_STR_E1; // TODO
  PROGMEM Language_Str MSG_AMAX_E2                         = _UxGT("Amax ") LCD_STR_E2; // TODO
  PROGMEM Language_Str MSG_AMAX_E3                         = _UxGT("Amax ") LCD_STR_E3; // TODO
  PROGMEM Language_Str MSG_AMAX_E4                         = _UxGT("Amax ") LCD_STR_E4; // TODO
  PROGMEM Language_Str MSG_AMAX_E5                         = _UxGT("Amax ") LCD_STR_E5; // TODO

  PROGMEM Language_Str MSG_A_RETRACT                       = _UxGT("A-retract");
  PROGMEM Language_Str MSG_A_TRAVEL                        = _UxGT("A-reise");

  
  PROGMEM Language_Str MSG_STEPS_PER_MM                    = _UxGT("Steps/mm"); // TODO
  PROGMEM Language_Str MSG_A_STEPS                         = LCD_STR_A _UxGT("steps/mm"); // TODO
  PROGMEM Language_Str MSG_B_STEPS                         = LCD_STR_B _UxGT("steps/mm"); // TODO
  PROGMEM Language_Str MSG_C_STEPS                         = LCD_STR_C _UxGT("steps/mm"); // TODO
  PROGMEM Language_Str MSG_E_STEPS                         = _UxGT("Esteps/mm"); // TODO
  PROGMEM Language_Str MSG_E0_STEPS                        = LCD_STR_E0 _UxGT("steps/mm"); // TODO
  PROGMEM Language_Str MSG_E1_STEPS                        = LCD_STR_E1 _UxGT("steps/mm"); // TODO
  PROGMEM Language_Str MSG_E2_STEPS                        = LCD_STR_E2 _UxGT("steps/mm"); // TODO
  PROGMEM Language_Str MSG_E3_STEPS                        = LCD_STR_E3 _UxGT("steps/mm"); // TODO
  PROGMEM Language_Str MSG_E4_STEPS                        = LCD_STR_E4 _UxGT("steps/mm"); // TODO
  PROGMEM Language_Str MSG_E5_STEPS                        = LCD_STR_E5 _UxGT("steps/mm"); // TODO

  PROGMEM Language_Str MSG_TEMPERATURE                     = _UxGT("Temperatur");
  PROGMEM Language_Str MSG_MOTION                          = _UxGT("Bevegelse");
  PROGMEM Language_Str MSG_FILAMENT                        = _UxGT("Filament");
  PROGMEM Language_Str MSG_VOLUMETRIC_ENABLED              = _UxGT("E i mm3");
  PROGMEM Language_Str MSG_FILAMENT_DIAM                   = _UxGT("Fil. Dia.");
  PROGMEM Language_Str MSG_FILAMENT_DIAM_E0                = _UxGT("Fil. Dia. ") LCD_STR_E0;
  PROGMEM Language_Str MSG_FILAMENT_DIAM_E1                = _UxGT("Fil. Dia. ") LCD_STR_E1;
  PROGMEM Language_Str MSG_FILAMENT_DIAM_E2                = _UxGT("Fil. Dia. ") LCD_STR_E2;
  PROGMEM Language_Str MSG_FILAMENT_DIAM_E3                = _UxGT("Fil. Dia. ") LCD_STR_E3;
  PROGMEM Language_Str MSG_FILAMENT_DIAM_E4                = _UxGT("Fil. Dia. ") LCD_STR_E4;
  PROGMEM Language_Str MSG_FILAMENT_DIAM_E5                = _UxGT("Fil. Dia. ") LCD_STR_E5;

  PROGMEM Language_Str MSG_FILAMENT_UNLOAD                 = _UxGT("Unload mm"); // TODO
  PROGMEM Language_Str MSG_FILAMENT_LOAD                   = _UxGT("Load mm"); // TODO
  PROGMEM Language_Str MSG_ADVANCE_K                       = _UxGT("Advance K"); // TODO
  PROGMEM Language_Str MSG_ADVANCE_K_E0                    = _UxGT("Advance K ") LCD_STR_E0 // TODO
  PROGMEM Language_Str MSG_ADVANCE_K_E1                    = _UxGT("Advance K ") LCD_STR_E1 // TODO
  PROGMEM Language_Str MSG_ADVANCE_K_E2                    = _UxGT("Advance K ") LCD_STR_E2 // TODO
  PROGMEM Language_Str MSG_ADVANCE_K_E3                    = _UxGT("Advance K ") LCD_STR_E3 // TODO
  PROGMEM Language_Str MSG_ADVANCE_K_E4                    = _UxGT("Advance K ") LCD_STR_E4 // TODO
  PROGMEM Language_Str MSG_ADVANCE_K_E5                    = _UxGT("Advance K ") LCD_STR_E5 // TODO

  PROGMEM Language_Str MSG_CONTRAST                        = _UxGT("LCD kontrast"); // TODO
  PROGMEM Language_Str MSG_STORE_EEPROM                    = _UxGT("Lagre i EEPROM"); // TODO
  PROGMEM Language_Str MSG_LOAD_EEPROM                     = _UxGT("Hent fra EEPROM"); // TODO
  PROGMEM Language_Str MSG_RESTORE_FAILSAFE                = _UxGT("Gjenopprett failsafe"); // TODO
  
  PROGMEM Language_Str MSG_INIT_EEPROM                     = _UxGT("Initialize EEPROM");
  PROGMEM Language_Str MSG_MEDIA_UPDATE                    = _UxGT("Media Update");
  PROGMEM Language_Str MSG_RESET_PRINTER                   = _UxGT("Reset Printer");

  PROGMEM Language_Str MSG_REFRESH                         = LCD_STR_REFRESH  _UxGT("Oppdater");
  PROGMEM Language_Str MSG_WATCH                           = _UxGT("Info skjerm");
  PROGMEM Language_Str MSG_PREPARE                         = _UxGT("Forbered");

  PROGMEM Language_Str MSG_TUNE                            = _UxGT("Tune"); // TODO
  PROGMEM Language_Str MSG_START_PRINT                     = _UxGT("Start Print"); // TODO
  PROGMEM Language_Str MSG_BUTTON_NEXT                     = _UxGT("Next"); // TODO
  PROGMEM Language_Str MSG_BUTTON_INIT                     = _UxGT("Init"); // TODO
  PROGMEM Language_Str MSG_BUTTON_STOP                     = _UxGT("Stop"); // TODO
  PROGMEM Language_Str MSG_BUTTON_PRINT                    = _UxGT("Print"); // TODO
  PROGMEM Language_Str MSG_BUTTON_RESET                    = _UxGT("Reset"); // TODO
  PROGMEM Language_Str MSG_BUTTON_CANCEL                   = _UxGT("Cancel"); // TODO
  PROGMEM Language_Str MSG_BUTTON_DONE                     = _UxGT("Done"); // TODO

  PROGMEM Language_Str MSG_PAUSE_PRINT                     = _UxGT("Pause printen");
  PROGMEM Language_Str MSG_RESUME_PRINT                    = _UxGT("Fortsett printen");
  PROGMEM Language_Str MSG_STOP_PRINT                      = _UxGT("Stopp printen");
  PROGMEM Language_Str MSG_MEDIA_MENU                      = _UxGT("Print fra SD");
  PROGMEM Language_Str MSG_NO_MEDIA                        = _UxGT("Ingen SD-kort");
  PROGMEM Language_Str MSG_DWELL                           = _UxGT("Dvale...");
  PROGMEM Language_Str MSG_USERWAIT                        = _UxGT("Venter på bruker...");

  PROGMEM Language_Str MSG_PRINT_PAUSED                    = _UxGT("Print Paused"); // TODO
  PROGMEM Language_Str MSG_PRINTING                        = _UxGT("Printing..."); // TODO

  PROGMEM Language_Str MSG_PRINT_ABORTED                   = _UxGT("Print avbrutt");
  PROGMEM Language_Str MSG_NO_MOVE                         = _UxGT("Trinnmotorer på.");
  PROGMEM Language_Str MSG_KILLED                          = _UxGT("DREPT. ");
  PROGMEM Language_Str MSG_STOPPED                         = _UxGT("STOPPET. ");
  PROGMEM Language_Str MSG_CONTROL_RETRACT                 = _UxGT("Tilbaketrekk mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_SWAP            = _UxGT("Endre Re.mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACTF                = _UxGT("Tilbaketrekk V");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_ZHOP            = _UxGT("Hopp mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVER         = _UxGT("UnRet mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVER_SWAP    = _UxGT("Endre UnRet mm");
  PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVERF        = _UxGT("UnRet  V");
  PROGMEM Language_Str MSG_AUTORETRACT                     = _UxGT("AutoRetr.");
  PROGMEM Language_Str MSG_FILAMENTCHANGE                  = _UxGT("Bytt filament");
  PROGMEM Language_Str MSG_FILAMENTCHANGE_E0               = _UxGT("Bytt filament ") LCD_STR_E0;
  PROGMEM Language_Str MSG_FILAMENTCHANGE_E1               = _UxGT("Bytt filament ") LCD_STR_E1;
  PROGMEM Language_Str MSG_FILAMENTCHANGE_E2               = _UxGT("Bytt filament ") LCD_STR_E2;
  PROGMEM Language_Str MSG_FILAMENTCHANGE_E3               = _UxGT("Bytt filament ") LCD_STR_E3;
  PROGMEM Language_Str MSG_FILAMENTCHANGE_E4               = _UxGT("Bytt filament ") LCD_STR_E4;
  PROGMEM Language_Str MSG_FILAMENTCHANGE_E5               = _UxGT("Bytt filament ") LCD_STR_E5;
  PROGMEM Language_Str MSG_CHANGE_MEDIA                    = _UxGT("Bytt SD-kort");
  PROGMEM Language_Str MSG_ZPROBE_OUT                      = _UxGT("Z-Probe utenfor seng");
  PROGMEM Language_Str MSG_BLTOUCH_SELFTEST                = _UxGT("BLTouch Selv-Test");
  PROGMEM Language_Str MSG_HOME_FIRST                      = _UxGT("Hjem %s%s%s først");
  PROGMEM Language_Str MSG_HEATING_FAILED_LCD              = _UxGT("Opvarmning feilet");
  PROGMEM Language_Str MSG_ERR_REDUNDANT_TEMP              = _UxGT("Feil: reserve temp");
  PROGMEM Language_Str MSG_THERMAL_RUNAWAY                 = _UxGT("Temp løper løpsk");
  PROGMEM Language_Str MSG_ERR_MAXTEMP                     = _UxGT("Feil: Maks temp");
  PROGMEM Language_Str MSG_ERR_MINTEMP                     = _UxGT("Feil: Min temp");
  PROGMEM Language_Str MSG_ERR_MAXTEMP_BED                 = _UxGT("Feil: Maks Sengetemp.");
  PROGMEM Language_Str MSG_ERR_MINTEMP_BED                 = _UxGT("Feil: Min Sengetemp.");
  PROGMEM Language_Str MSG_ERR_Z_HOMING                    = _UxGT("Hjem XY først");
  PROGMEM Language_Str MSG_HALTED                          = _UxGT("PRINTER STOPPET");
  PROGMEM Language_Str MSG_PLEASE_RESET                    = _UxGT("Vennligst tilbakestill");
  PROGMEM Language_Str MSG_SHORT_DAY                       = _UxGT("d"); // Kun et bogstav
  PROGMEM Language_Str MSG_SHORT_HOUR                      = _UxGT("h"); // Kun et bogstav
  PROGMEM Language_Str MSG_SHORT_MINUTE                    = _UxGT("m"); // Kun et bogstav
  PROGMEM Language_Str MSG_HEATING                         = _UxGT("Varmer...");
  PROGMEM Language_Str MSG_BED_HEATING                     = _UxGT("Varmer seng...");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE                 = _UxGT("Delta-kalibrering");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE_X               = _UxGT("Kalibrer X");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE_Y               = _UxGT("Kalibrer Y");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE_Z               = _UxGT("Kalibrer Z");
  PROGMEM Language_Str MSG_DELTA_CALIBRATE_CENTER          = _UxGT("Kalibreringssenter");

  PROGMEM Language_Str MSG_INFO_MENU                       = _UxGT("Om Printer");
  PROGMEM Language_Str MSG_INFO_BOARD_MENU                 = _UxGT("Kort Info");
  PROGMEM Language_Str MSG_INFO_THERMISTOR_MENU            = _UxGT("Termistorer");

  #if LCD_WIDTH >= 20
    PROGMEM Language_Str MSG_INFO_PRINT_COUNT              = _UxGT("Ant. Printer");
    PROGMEM Language_Str MSG_INFO_COMPLETED_PRINTS         = _UxGT("Ferdige");
    PROGMEM Language_Str MSG_INFO_PRINT_TIME               = _UxGT("Total print tid");
    PROGMEM Language_Str MSG_INFO_PRINT_LONGEST            = _UxGT("Lengste print");
    PROGMEM Language_Str MSG_INFO_PRINT_FILAMENT           = _UxGT("Total Ekstrudert");
  #else
    PROGMEM Language_Str MSG_INFO_PRINT_COUNT              = _UxGT("Printer");
    PROGMEM Language_Str MSG_INFO_COMPLETED_PRINTS         = _UxGT("Ferdige");
    PROGMEM Language_Str MSG_INFO_PRINT_TIME               = _UxGT("Total");
    PROGMEM Language_Str MSG_INFO_PRINT_LONGEST            = _UxGT("Lengste");
    PROGMEM Language_Str MSG_INFO_PRINT_FILAMENT           = _UxGT("Ekstrudert");
  #endif

  PROGMEM Language_Str MSG_INFO_PSU                        = _UxGT("Strømfors.");

  PROGMEM Language_Str MSG_DRIVE_STRENGTH                  = _UxGT("Drivstyrke");
  PROGMEM Language_Str MSG_DAC_PERCENT                     = _UxGT("Driv %");
  PROGMEM Language_Str MSG_DAC_EEPROM_WRITE                = _UxGT("DAC EEPROM Skriv");

  PROGMEM Language_Str MSG_FILAMENT_CHANGE_OPTION_RESUME   = _UxGT("Fortsett print");

  PROGMEM Language_Str MSG_EXPECTED_PRINTER                = _UxGT("Feil printer");

  #if LCD_HEIGHT >= 4
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_INIT          = _UxGT(MSG_3_LINE("Vent på start", "av filament", "bytt"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_UNLOAD        = _UxGT(MSG_2_LINE("Vent på", "filament utstøtes."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_INSERT        = _UxGT(MSG_3_LINE("Laster inn filament", "og trykk på knappen", "for å fortsette"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_LOAD          = _UxGT(MSG_2_LINE("Vent på", "filament laster inn"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_RESUME        = _UxGT(MSG_2_LINE("Vent på at print", "fortsetter"));
  #else // LCD_HEIGHT < 4
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_INIT          = _UxGT(MSG_1_LINE("Vennligst vent..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_UNLOAD        = _UxGT(MSG_1_LINE("Utstøter..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_INSERT        = _UxGT(MSG_1_LINE("Sett inn og klikk"));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_LOAD          = _UxGT(MSG_1_LINE("Laster inn..."));
    PROGMEM Language_Str MSG_FILAMENT_CHANGE_RESUME        = _UxGT(MSG_1_LINE("Fortsetter..."));
  #endif // LCD_HEIGHT < 4
}



# SJEKK ALLE ETTER DENNE


PROGMEM Language_Str MSG_PRINT_ABORTED                   = _UxGT("Print Aborted");
PROGMEM Language_Str MSG_NO_MOVE                         = _UxGT("Motors enabled.");
PROGMEM Language_Str MSG_KILLED                          = _UxGT("KILLED. ");
PROGMEM Language_Str MSG_STOPPED                         = _UxGT("STOPPED. ");
PROGMEM Language_Str MSG_CONTROL_RETRACT                 = _UxGT("Retract mm");
PROGMEM Language_Str MSG_CONTROL_RETRACT_SWAP            = _UxGT("Swap Re.mm");
PROGMEM Language_Str MSG_CONTROL_RETRACTF                = _UxGT("Retract  V");
PROGMEM Language_Str MSG_CONTROL_RETRACT_ZHOP            = _UxGT("Hop mm");
PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVER         = _UxGT("UnRet mm");
PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVER_SWAP    = _UxGT("S UnRet mm");
PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVERF        = _UxGT("UnRet V");
PROGMEM Language_Str MSG_CONTROL_RETRACT_RECOVER_SWAPF   = _UxGT("S UnRet V");
PROGMEM Language_Str MSG_AUTORETRACT                     = _UxGT("AutoRetr.");
PROGMEM Language_Str MSG_FILAMENT_SWAP_LENGTH            = _UxGT("Swap Length");
PROGMEM Language_Str MSG_FILAMENT_PURGE_LENGTH           = _UxGT("Purge Length");
PROGMEM Language_Str MSG_TOOL_CHANGE                     = _UxGT("Tool Change");
PROGMEM Language_Str MSG_TOOL_CHANGE_ZLIFT               = _UxGT("Z Raise");
PROGMEM Language_Str MSG_SINGLENOZZLE_PRIME_SPD          = _UxGT("Prime Speed");
PROGMEM Language_Str MSG_SINGLENOZZLE_RETRACT_SPD        = _UxGT("Retract Speed");
PROGMEM Language_Str MSG_NOZZLE_STANDBY                  = _UxGT("Nozzle Standby");
PROGMEM Language_Str MSG_FILAMENTCHANGE                  = _UxGT("Change Filament");
PROGMEM Language_Str MSG_FILAMENTCHANGE_E0               = _UxGT("Change Filament ") LCD_STR_E0;
PROGMEM Language_Str MSG_FILAMENTCHANGE_E1               = _UxGT("Change Filament ") LCD_STR_E1;
PROGMEM Language_Str MSG_FILAMENTCHANGE_E2               = _UxGT("Change Filament ") LCD_STR_E2;
PROGMEM Language_Str MSG_FILAMENTCHANGE_E3               = _UxGT("Change Filament ") LCD_STR_E3;
PROGMEM Language_Str MSG_FILAMENTCHANGE_E4               = _UxGT("Change Filament ") LCD_STR_E4;
PROGMEM Language_Str MSG_FILAMENTCHANGE_E5               = _UxGT("Change Filament ") LCD_STR_E5;
PROGMEM Language_Str MSG_FILAMENTLOAD                    = _UxGT("Load Filament");
PROGMEM Language_Str MSG_FILAMENTLOAD_E0                 = _UxGT("Load Filament ") LCD_STR_E0;
PROGMEM Language_Str MSG_FILAMENTLOAD_E1                 = _UxGT("Load Filament ") LCD_STR_E1;
PROGMEM Language_Str MSG_FILAMENTLOAD_E2                 = _UxGT("Load Filament ") LCD_STR_E2;
PROGMEM Language_Str MSG_FILAMENTLOAD_E3                 = _UxGT("Load Filament ") LCD_STR_E3;
PROGMEM Language_Str MSG_FILAMENTLOAD_E4                 = _UxGT("Load Filament ") LCD_STR_E4;
PROGMEM Language_Str MSG_FILAMENTLOAD_E5                 = _UxGT("Load Filament ") LCD_STR_E5;
PROGMEM Language_Str MSG_FILAMENTUNLOAD                  = _UxGT("Unload Filament");
PROGMEM Language_Str MSG_FILAMENTUNLOAD_E0               = _UxGT("Unload Filament ") LCD_STR_E0;
PROGMEM Language_Str MSG_FILAMENTUNLOAD_E1               = _UxGT("Unload Filament ") LCD_STR_E1;
PROGMEM Language_Str MSG_FILAMENTUNLOAD_E2               = _UxGT("Unload Filament ") LCD_STR_E2;
PROGMEM Language_Str MSG_FILAMENTUNLOAD_E3               = _UxGT("Unload Filament ") LCD_STR_E3;
PROGMEM Language_Str MSG_FILAMENTUNLOAD_E4               = _UxGT("Unload Filament ") LCD_STR_E4;
PROGMEM Language_Str MSG_FILAMENTUNLOAD_E5               = _UxGT("Unload Filament ") LCD_STR_E5;
PROGMEM Language_Str MSG_FILAMENTUNLOAD_ALL              = _UxGT("Unload All");
PROGMEM Language_Str MSG_INIT_MEDIA                      = _UxGT("Init. Media");
PROGMEM Language_Str MSG_CHANGE_MEDIA                    = _UxGT("Change Media");
PROGMEM Language_Str MSG_RELEASE_MEDIA                   = _UxGT("Release Media");
PROGMEM Language_Str MSG_ZPROBE_OUT                      = _UxGT("Z Probe Past Bed");
PROGMEM Language_Str MSG_SKEW_FACTOR                     = _UxGT("Skew Factor");
PROGMEM Language_Str MSG_BLTOUCH                         = _UxGT("BLTouch");
PROGMEM Language_Str MSG_BLTOUCH_SELFTEST                = _UxGT("Cmd: Self-Test");
PROGMEM Language_Str MSG_BLTOUCH_RESET                   = _UxGT("Cmd: Reset");
PROGMEM Language_Str MSG_BLTOUCH_STOW                    = _UxGT("Cmd: Stow");
PROGMEM Language_Str MSG_BLTOUCH_DEPLOY                  = _UxGT("Cmd: Deploy");
PROGMEM Language_Str MSG_BLTOUCH_SW_MODE                 = _UxGT("Cmd: SW-Mode");
PROGMEM Language_Str MSG_BLTOUCH_5V_MODE                 = _UxGT("Cmd: 5V-Mode");
PROGMEM Language_Str MSG_BLTOUCH_OD_MODE                 = _UxGT("Cmd: OD-Mode");
PROGMEM Language_Str MSG_BLTOUCH_MODE_STORE              = _UxGT("Cmd: Mode-Store");
PROGMEM Language_Str MSG_BLTOUCH_MODE_STORE_5V           = _UxGT("Set BLTouch to 5V");
PROGMEM Language_Str MSG_BLTOUCH_MODE_STORE_OD           = _UxGT("Set BLTouch to OD");
PROGMEM Language_Str MSG_BLTOUCH_MODE_ECHO               = _UxGT("Report Drain");
PROGMEM Language_Str MSG_BLTOUCH_MODE_CHANGE             = _UxGT("DANGER: Bad settings can cause damage! Proceed anyway?");
PROGMEM Language_Str MSG_TOUCHMI_PROBE                   = _UxGT("TouchMI");
PROGMEM Language_Str MSG_TOUCHMI_INIT                    = _UxGT("Init TouchMI");
PROGMEM Language_Str MSG_TOUCHMI_ZTEST                   = _UxGT("Z Offset Test");
PROGMEM Language_Str MSG_TOUCHMI_SAVE                    = _UxGT("Save");
PROGMEM Language_Str MSG_MANUAL_DEPLOY_TOUCHMI           = _UxGT("Deploy TouchMI");
PROGMEM Language_Str MSG_MANUAL_DEPLOY                   = _UxGT("Deploy Z-Probe");
PROGMEM Language_Str MSG_MANUAL_STOW                     = _UxGT("Stow Z-Probe");
PROGMEM Language_Str MSG_HOME_FIRST                      = _UxGT("Home %s%s%s First");
PROGMEM Language_Str MSG_ZPROBE_ZOFFSET                  = _UxGT("Probe Z Offset");
PROGMEM Language_Str MSG_BABYSTEP_X                      = _UxGT("Babystep X");
PROGMEM Language_Str MSG_BABYSTEP_Y                      = _UxGT("Babystep Y");
PROGMEM Language_Str MSG_BABYSTEP_Z                      = _UxGT("Babystep Z");
PROGMEM Language_Str MSG_BABYSTEP_TOTAL                  = _UxGT("Total");
PROGMEM Language_Str MSG_ENDSTOP_ABORT                   = _UxGT("Endstop Abort");
PROGMEM Language_Str MSG_HEATING_FAILED_LCD              = _UxGT("Heating Failed");
PROGMEM Language_Str MSG_HEATING_FAILED_LCD_BED          = _UxGT("Bed Heating Failed");
PROGMEM Language_Str MSG_HEATING_FAILED_LCD_CHAMBER      = _UxGT("Chamber Heating Fail");
PROGMEM Language_Str MSG_ERR_REDUNDANT_TEMP              = _UxGT("Err: REDUNDANT TEMP");
PROGMEM Language_Str MSG_THERMAL_RUNAWAY                 = _UxGT("THERMAL RUNAWAY");
PROGMEM Language_Str MSG_THERMAL_RUNAWAY_BED             = _UxGT("BED THERMAL RUNAWAY");
PROGMEM Language_Str MSG_THERMAL_RUNAWAY_CHAMBER         = _UxGT("CHAMBER T. RUNAWAY");
PROGMEM Language_Str MSG_ERR_MAXTEMP                     = _UxGT("Err: MAXTEMP");
PROGMEM Language_Str MSG_ERR_MINTEMP                     = _UxGT("Err: MINTEMP");
PROGMEM Language_Str MSG_ERR_MINTEMP_HEATBREAK           = _UxGT("Err: MINTEMP HBR");
PROGMEM Language_Str MSG_ERR_MAXTEMP_HEATBREAK           = _UxGT("Err: MAXTEMP HBR");
PROGMEM Language_Str MSG_ERR_MAXTEMP_BED                 = _UxGT("Err: MAXTEMP BED");
PROGMEM Language_Str MSG_ERR_MINTEMP_BED                 = _UxGT("Err: MINTEMP BED");
PROGMEM Language_Str MSG_ERR_MAXTEMP_CHAMBER             = _UxGT("Err: MAXTEMP CHAMBER");
PROGMEM Language_Str MSG_ERR_MINTEMP_CHAMBER             = _UxGT("Err: MINTEMP CHAMBER");
PROGMEM Language_Str MSG_ERR_Z_HOMING                    = _UxGT("Home XY First");
PROGMEM Language_Str MSG_ERR_HOMING_X                    = _UxGT("HOMING ERROR X");
PROGMEM Language_Str MSG_ERR_HOMING_Y                    = _UxGT("HOMING ERROR Y");
PROGMEM Language_Str MSG_ERR_HOMING_Z                    = _UxGT("HOMING ERROR Z");
PROGMEM Language_Str MSG_HALTED                          = _UxGT("PRINTER HALTED");
PROGMEM Language_Str MSG_PLEASE_RESET                    = _UxGT("Please Reset");
PROGMEM Language_Str MSG_SHORT_DAY                       = _UxGT("d"); // One character only
PROGMEM Language_Str MSG_SHORT_HOUR                      = _UxGT("h"); // One character only
PROGMEM Language_Str MSG_SHORT_MINUTE                    = _UxGT("m"); // One character only
PROGMEM Language_Str MSG_HEATING                         = _UxGT("Heating...");
PROGMEM Language_Str MSG_COOLING                         = _UxGT("Cooling...");
PROGMEM Language_Str MSG_BED_HEATING                     = _UxGT("Bed Heating...");
PROGMEM Language_Str MSG_BED_COOLING                     = _UxGT("Bed Cooling...");
PROGMEM Language_Str MSG_CHAMBER_HEATING                 = _UxGT("Chamber Heating...");
PROGMEM Language_Str MSG_CHAMBER_COOLING                 = _UxGT("Chamber Cooling...");
PROGMEM Language_Str MSG_DELTA_CALIBRATE                 = _UxGT("Delta Calibration");
PROGMEM Language_Str MSG_DELTA_CALIBRATE_X               = _UxGT("Calibrate X");
PROGMEM Language_Str MSG_DELTA_CALIBRATE_Y               = _UxGT("Calibrate Y");
PROGMEM Language_Str MSG_DELTA_CALIBRATE_Z               = _UxGT("Calibrate Z");
PROGMEM Language_Str MSG_DELTA_CALIBRATE_CENTER          = _UxGT("Calibrate Center");
PROGMEM Language_Str MSG_DELTA_SETTINGS                  = _UxGT("Delta Settings");
PROGMEM Language_Str MSG_DELTA_AUTO_CALIBRATE            = _UxGT("Auto Calibration");
PROGMEM Language_Str MSG_DELTA_HEIGHT_CALIBRATE          = _UxGT("Set Delta Height");
PROGMEM Language_Str MSG_DELTA_Z_OFFSET_CALIBRATE        = _UxGT("Probe Z-offset");
PROGMEM Language_Str MSG_DELTA_DIAG_ROD                  = _UxGT("Diag Rod");
PROGMEM Language_Str MSG_DELTA_HEIGHT                    = _UxGT("Height");
PROGMEM Language_Str MSG_DELTA_RADIUS                    = _UxGT("Radius");
PROGMEM Language_Str MSG_INFO_MENU                       = _UxGT("About Printer");
PROGMEM Language_Str MSG_INFO_PRINTER_MENU               = _UxGT("Printer Info");
PROGMEM Language_Str MSG_3POINT_LEVELING                 = _UxGT("3-Point Leveling");
PROGMEM Language_Str MSG_LINEAR_LEVELING                 = _UxGT("Linear Leveling");
PROGMEM Language_Str MSG_BILINEAR_LEVELING               = _UxGT("Bilinear Leveling");
PROGMEM Language_Str MSG_UBL_LEVELING                    = _UxGT("Unified Bed Leveling");
PROGMEM Language_Str MSG_MESH_LEVELING                   = _UxGT("Mesh Leveling");
PROGMEM Language_Str MSG_INFO_STATS_MENU                 = _UxGT("Printer Stats");
PROGMEM Language_Str MSG_INFO_BOARD_MENU                 = _UxGT("Board Info");
PROGMEM Language_Str MSG_INFO_THERMISTOR_MENU            = _UxGT("Thermistors");
PROGMEM Language_Str MSG_INFO_EXTRUDERS                  = _UxGT("Extruders");
PROGMEM Language_Str MSG_INFO_BAUDRATE                   = _UxGT("Baud");
PROGMEM Language_Str MSG_INFO_PROTOCOL                   = _UxGT("Protocol");
PROGMEM Language_Str MSG_INFO_RUNAWAY_OFF                = _UxGT("Runaway Watch: OFF");
PROGMEM Language_Str MSG_INFO_RUNAWAY_ON                 = _UxGT("Runaway Watch: ON");

PROGMEM Language_Str MSG_CASE_LIGHT                      = _UxGT("Case Light");
PROGMEM Language_Str MSG_CASE_LIGHT_BRIGHTNESS           = _UxGT("Light Brightness");
PROGMEM Language_Str MSG_EXPECTED_PRINTER                = _UxGT("INCORRECT PRINTER");
