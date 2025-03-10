/*
@ @licstart  The following is the entire license notice for the
JavaScript code in this file.

Copyright (C) 1997-2017 by Dimitri van Heesch

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

@licend  The above is the entire license notice
for the JavaScript code in this file
*/
var NAVTREE =
[
  [ "Dr. Memory", "index.html", [
    [ "Installing Dr. Memory", "page_install.html", "page_install" ],
    [ "Preparing Your Application", "page_prep.html", [
      [ "For All Platforms", "page_prep.html#sec_prep_general", [
        [ "Debug Information", "page_prep.html#sec_prep_debuginfo", null ],
        [ "Callstack Quality", "page_prep.html#sec_prep_callstacks", null ]
      ] ],
      [ "Linux", "page_prep.html#sec_prep_linux", null ],
      [ "Mac", "page_prep.html#sec_prep_mac", null ],
      [ "Windows Visual Studio", "page_prep.html#sec_prep_windows", [
        [ "C Library Interactions", "page_prep.html#sec_prep_win_libc", null ],
        [ "Disable Runtime Checks", "page_prep.html#sec_prep_win_rtc", null ],
        [ "Parameter Summary", "page_prep.html#sec_prep_win_sum", null ]
      ] ],
      [ "Windows MinGW", "page_prep.html#sec_prep_mingw", null ],
      [ "Windows Cygwin: Not Supported", "page_prep.html#sec_prep_cygwin", null ],
      [ "Android", "page_prep.html#sec_prep_android", null ]
    ] ],
    [ "Running Dr. Memory", "page_running.html", [
      [ "Dr. Memory as a Visual Studio Tool", "page_running.html#sec_vstudio", null ],
      [ "Invoking Dr. Memory from the Command Line", "page_running.html#sec_invocation", null ],
      [ "Examining the Results", "page_running.html#sec_results", [
        [ "Application Versus System Library Errors", "page_running.html#sec_potential_errors", null ],
        [ "Eliminating Uninitialized Read Checks By Library", "page_running.html#sec_no_uninit_checks", null ]
      ] ],
      [ "Controlling Child Processes", "page_running.html#sec_children", null ],
      [ "Applications That Do Not Exit", "page_running.html#sec_daemon", null ],
      [ "Tuning for Performance", "page_running.html#sec_perf", null ]
    ] ],
    [ "Error Types Reported by Dr. Memory", "page_types.html", "page_types" ],
    [ "Error Reports", "page_reports.html", "page_reports" ],
    [ "Light Mode", "page_light.html", null ],
    [ "Fuzz Testing Mode", "page_fuzzer.html", [
      [ "Fuzzer Target", "page_fuzzer.html#sec_fuzzer_target", null ],
      [ "C++ Targets", "page_fuzzer.html#sec_cpp_targets", null ],
      [ "Calling Conventions", "page_fuzzer.html#sec_calling_conventions", null ],
      [ "Mutator", "page_fuzzer.html#sec_mutator", null ],
      [ "Dumping and Loading Fuzz Input Data", "page_fuzzer.html#sec_dump_load", null ],
      [ "Corpus-Based Fuzzing", "page_fuzzer.html#sec_corpus", null ]
    ] ],
    [ "Code Coverage", "page_coverage.html", [
      [ "Enabling Coverage Information", "page_coverage.html#sec_enable", null ],
      [ "Post Processing", "page_coverage.html#sec_postproc", null ]
    ] ],
    [ "Dr. Memory Runtime Option Reference", "page_options.html", null ],
    [ "Release Notes for Version 2.3.0", "page_release_notes.html", [
      [ "Distribution Contents", "page_release_notes.html#sec_package", null ],
      [ "Changes Since Prior Releases", "page_release_notes.html#sec_changes", null ],
      [ "Limitations", "page_release_notes.html#sec_limits", [
        [ "Interoperability", "page_release_notes.html#sec_interop", null ]
      ] ]
    ] ],
    [ "Obtaining Help and Reporting Bugs", "page_help.html", null ],
    [ "License for Dr. Memory", "page_license.html", null ],
    [ "Additional Tools", "page_tools.html", "page_tools" ],
    [ "Dr. Memory Framework", "page_drmf.html", "page_drmf" ],
    [ "Deprecated List", "deprecated.html", null ],
    [ "DRMF Modules", "modules.html", "modules" ],
    [ "Data Structures", "annotated.html", [
      [ "Data Structures", "annotated.html", "annotated_dup" ],
      [ "Data Fields", "functions.html", [
        [ "All", "functions.html", null ],
        [ "Variables", "functions_vars.html", null ]
      ] ]
    ] ],
    [ "Files", "files.html", [
      [ "File List", "files.html", "files_dup" ],
      [ "Globals", "globals.html", [
        [ "All", "globals.html", "globals_dup" ],
        [ "Functions", "globals_func.html", null ],
        [ "Typedefs", "globals_type.html", null ],
        [ "Enumerations", "globals_enum.html", null ],
        [ "Enumerator", "globals_eval.html", null ],
        [ "Macros", "globals_defs.html", null ]
      ] ]
    ] ],
    [ "Dr. Memory Home Page", "^http://www.drmemory.org", null ]
  ] ]
];

var NAVTREEINDEX =
[
"annotated.html",
"group__drsyscall.html#gga06fc87d81c62e9abb8790b6e5713c55baa805229054c9ea0bd956ec60fd3f148a",
"page_fuzzer.html#sec_corpus"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';