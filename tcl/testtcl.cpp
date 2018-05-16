#include <stdio.h>
#include <tcl.h>
#include <unistd.h>

extern "C" {
    int Testtcl_Init(Tcl_Interp *Interp);
}

int Action_Test1( int notUsed, Tcl_Interp *interp, int argc, char **argv) {
    if ( argc != 2 ) {
        Tcl_SetResult(interp, "Usage::Action_Test1 param1",
            TCL_VOLATILE);
        return TCL_ERROR;
    }
    printf("Action_Test1: param1=%s\n", argv[1]);
    Tcl_SetResult(interp, argv[1], TCL_VOLATILE);
    return TCL_OK;
}

int Action_Test2( int notUsed, Tcl_Interp *interp, int argc, char **argv) {
    if ( argc != 2 ) {
        Tcl_SetResult(interp, "Usage::Action_Test2 param1",
            TCL_VOLATILE);
        return TCL_ERROR;
    }
    printf("Action_Test2: param1=%s\n", argv[1]);
    return TCL_OK;
}

int Testtcl_Init(Tcl_Interp *Interp) {
    Tcl_CreateCommand (Interp, "Action_Test1",    (Tcl_CmdProc *)Action_Test1,    0, 0);
    Tcl_CreateCommand (Interp, "Action_Test2", (Tcl_CmdProc *)Action_Test2, 0, 0);
    return TCL_OK;
}

int Testtcl_Unload( Tcl_Interp *Interp, int flags) {
    return TCL_OK;
}
