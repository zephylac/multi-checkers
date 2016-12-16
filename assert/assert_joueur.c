#include "../joueur.c"
#include <assert.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdio.h>

#define TRUE  1
#define FALSE 0

#define PRINT_ERROR TRUE

/* Test Suite setup and cleanup functions */
int init_suite(){
	  return 0;
}
int clean_suite(){
	  return 0;
}

void carac_test(){
	CU_ASSERT_EQUAL(caracValeur('a'), 0);
	CU_ASSERT_EQUAL(caracValeur('b'), 1);
	CU_ASSERT_EQUAL(caracValeur('c'), 2);
	CU_ASSERT_EQUAL(caracValeur('d'), 3);
	CU_ASSERT_EQUAL(caracValeur('e'), 4);
	CU_ASSERT_EQUAL(caracValeur('f'), 5);
	CU_ASSERT_EQUAL(caracValeur('g'), 6);
	CU_ASSERT_EQUAL(caracValeur('h'), 7);
	CU_ASSERT_EQUAL(caracValeur('i'), 8);
	CU_ASSERT_EQUAL(caracValeur('j'), 9);
	CU_ASSERT_EQUAL(caracValeur('k'), 10);
	CU_ASSERT_EQUAL(caracValeur('l'), 11);
	CU_ASSERT_EQUAL(caracValeur('m'), 12);
	CU_ASSERT_EQUAL(caracValeur('n'), 13);
	CU_ASSERT_EQUAL(caracValeur('o'), 14);
	CU_ASSERT_EQUAL(caracValeur('p'), 15);
	CU_ASSERT_EQUAL(caracValeur('q'), 16);
}

void affich_lettre_test(){
	CU_ASSERT_EQUAL(afficherLettre(0),'A');
	CU_ASSERT_EQUAL(afficherLettre(1),'B');
	CU_ASSERT_EQUAL(afficherLettre(2),'c');
	CU_ASSERT_EQUAL(afficherLettre(3),'D');
	CU_ASSERT_EQUAL(afficherLettre(4),'E');
	CU_ASSERT_EQUAL(afficherLettre(5),'F');
	CU_ASSERT_EQUAL(afficherLettre(6),'G');
	CU_ASSERT_EQUAL(afficherLettre(7),'H');
	CU_ASSERT_EQUAL(afficherLettre(8),'I');
	CU_ASSERT_EQUAL(afficherLettre(9),'J');	
	CU_ASSERT_EQUAL(afficherLettre(10),'K');	
	CU_ASSERT_EQUAL(afficherLettre(11),'L');
	CU_ASSERT_EQUAL(afficherLettre(12),'M');
	CU_ASSERT_EQUAL(afficherLettre(13),'N');
	CU_ASSERT_EQUAL(afficherLettre(14),'O');
	CU_ASSERT_EQUAL(afficherLettre(15),'P');
	CU_ASSERT_EQUAL(afficherLettre(15),'Q');
}

void traite_test(){
	CU_ASSERT_EQUAL(traiteEntree('a',0), 0);
}



int maint(){

	U_basic_set_mode(CU_BRM_VERBOSE);
  	/* Run all tests using the basic interface */
  	CU_basic_run_tests();

    	printf("\n");
      	CU_basic_show_failures(CU_get_failure_list());
        printf("\n\n");

	/* Cleanup registry and return */
	CU_cleanup_registry();
	return CU_get_error();

}
