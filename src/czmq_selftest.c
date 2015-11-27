/*  =========================================================================
    czmq_selftest.c - run selftests

    Runs all selftests.

    -------------------------------------------------------------------------
    Copyright (c) 1991-2012 iMatix Corporation -- http://www.imatix.com                
    Copyright other contributors as noted in the AUTHORS file.                         
                                                                                       
    This file is part of CZMQ, the high-level C binding for 0MQ: http://czmq.zeromq.org
                                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public                
    License, v. 2.0. If a copy of the MPL was not distributed with this                
    file, You can obtain one at http://mozilla.org/MPL/2.0/.                           

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
    =========================================================================
*/

#include "czmq_classes.h"

//  -------------------------------------------------------------------------
//  Prototype of test function
//

typedef void (*testfn_t) (bool);

//  -------------------------------------------------------------------------
//  Mapping of test class and test function.
//

typedef struct
{
    const char *testname;
    testfn_t test;
} test_item_t;

//  -------------------------------------------------------------------------
//  Declaration of all tests
//

#define DECLARE_TEST(TEST) {#TEST, TEST}

test_item_t all_tests [] = {
    DECLARE_TEST(zactor_test),
    DECLARE_TEST(zauth_test),
    DECLARE_TEST(zarmour_test),
    DECLARE_TEST(zbeacon_test),
    DECLARE_TEST(zcert_test),
    DECLARE_TEST(zcertstore_test),
    DECLARE_TEST(zchunk_test),
    DECLARE_TEST(zclock_test),
    DECLARE_TEST(zconfig_test),
    DECLARE_TEST(zdigest_test),
    DECLARE_TEST(zdir_test),
    DECLARE_TEST(zdir_patch_test),
    DECLARE_TEST(zfile_test),
    DECLARE_TEST(zframe_test),
    DECLARE_TEST(zgossip_test),
    DECLARE_TEST(zhashx_test),
    DECLARE_TEST(ziflist_test),
    DECLARE_TEST(zlistx_test),
    DECLARE_TEST(zloop_test),
    DECLARE_TEST(zmonitor_test),
    DECLARE_TEST(zmsg_test),
    DECLARE_TEST(zpoller_test),
    DECLARE_TEST(zproxy_test),
    DECLARE_TEST(zrex_test),
    DECLARE_TEST(zsock_test),
    DECLARE_TEST(zstr_test),
    DECLARE_TEST(zsys_test),
    DECLARE_TEST(ztrie_test),
    DECLARE_TEST(zuuid_test),
    DECLARE_TEST(zgossip_msg_test),
    DECLARE_TEST(zauth_v2_test),
    DECLARE_TEST(zbeacon_v2_test),
    DECLARE_TEST(zctx_test),
    DECLARE_TEST(zhash_test),
    DECLARE_TEST(zlist_test),
    DECLARE_TEST(zmonitor_v2_test),
    DECLARE_TEST(zmutex_test),
    DECLARE_TEST(zproxy_v2_test),
    DECLARE_TEST(zsocket_test),
    DECLARE_TEST(zsockopt_test),
    DECLARE_TEST(zthread_test),
    {0, 0} // Null terminator
};

//  -------------------------------------------------------------------------
//  Return the number of available tests.
//

static inline unsigned
test_get_number (void)
{
    unsigned count = 0;
    test_item_t *item;
    for (item = all_tests; item->test; item++)
        count++;
    return count;
}

//  -------------------------------------------------------------------------
//  Print names of all available tests to stdout.
//

static inline void
test_print_list (void)
{
    unsigned count = 0;
    test_item_t *item;
    for (item = all_tests; item->test; item++) {
        count++;
        printf ("%u:%s\n", count, item->testname);
    }
}

//  -------------------------------------------------------------------------
//  Test whether a test is available.
//  Return a pointer to a test_item_t if available, NULL otherwise.
//

test_item_t *
test_available (const char *testname)
{
    test_item_t *item;
    for (item = all_tests; item->test; item++) {
        if (streq (testname, item->testname))
            return item;
    }
    return NULL;
}

//  -------------------------------------------------------------------------
//  Run all tests.
//

static inline void
test_runall (bool verbose)
{
    printf ("Running czmq selftests...\n");
    test_item_t *item;
    for (item = all_tests; item->test; item++)
        item->test (verbose);

    printf ("Tests passed OK\n");
}

int
main (int argc, char **argv)
{
    bool verbose = false;
    test_item_t *test = 0;
    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "-v"))
            verbose = true;
        else
        if (streq (argv [argn], "--nb")) {
            printf("%d\n", test_get_number ());
            return 0;
        }
        else
        if (streq (argv [argn], "--list")) {
            test_print_list ();
            return 0;
        }
        else
        if (streq (argv [argn], "--test")) {
            argn++;
            if (argn >= argc) {
                fprintf (stderr, "--test needs an argument\n");
                return 1;
            }
            test = test_available (argv [argn]);
            if (!test) {
                fprintf (stderr, "%s is not available\n", argv [argn]);
                return 1;
            }
        }
        else
        if (streq (argv [argn], "-e")) {
#ifdef _MSC_VER
            //  When receiving an abort signal, only print to stderr (no dialog)
            _set_abort_behavior (0, _WRITE_ABORT_MSG);
#endif
        }
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }
    if (test) {
        printf ("Running czmq selftest '%s'...\n", test->testname);
        test->test (verbose);
    }
    else
        test_runall (verbose);

    return 0;
}
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
