#include "list.h"
#include "my_data.h"

void createList(List &L) {
    /**
    * FS : set first(L) with Null
    */

    first(L) = NULL;
}

address allocate(infotype x) {
    /**
    * FS : return new list element with info = x and next element is Null
    */

    //-------------your code here-------------
    address P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : delete element pointed by P
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the first element in List L
    */
    //-------------your code here-------------
    next(P) = first(L);
    first(L) = P;
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L may be empty
    * FS : element pointed by P became the last element in List L
    */
    //-------------your code here-------------
    address(Q) = first(L);
    if (first (L) == NULL) {
        insertFirst(L,P);
    }
    else {
        while(next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
    //----------------------------------------
}

address findElm(List L, infotype x) {
    /**
    * IS : List L may be empty
    * FS : returns element with info.ID = x.ID,
           return Null if such ID is not found
    */

    //-------------your code here-------------
    address P = first (L);
    while((info(P).id != x.id) && (P != NULL)) {
        P = next(P);
    }
    if (info (P).id == x.id ) {
        return P;
    }
    else {
        return NULL;
    }
    //----------------------------------------

}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L may be empty
    * FS : first element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    if(first(L) != NULL) {
        P = first(L);
        first(L)= next(P);
        next(P)= NULL;
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P)
{
    /**
    * IS : List L may be empty
    * FS : last element in List L is removed and is pointed by P
    */
    //-------------your code here-------------
    address Q;
    if (first(L) != NULL) {
        address Q = first(L);
    }
    if (next(first(L))== NULL) {
        P = first(L);
        first(L) = NULL;
    }
    else {
        while(next(next (Q)) != NULL) {
            Q = next(Q);
        }
        P = next (Q);
        next(Q) = NULL;
    }
    //----------------------------------------
}

void printInfo(List L) {
    /**
    * FS : view info of all element inside List L,
    *      call the view_data function from my_data.h to print the info
    */
    //-------------your code here-------------
    address P;
    P = first(L);
    while (P != NULL) {
        view_data (info(P));
        P = next(P);
    }
    //----------------------------------------
}

void insertAfter(address Prec, address P) {
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    //-------------your code here-------------
    next(P) = next(Prec);
    next(Prec) = P;
    //----------------------------------------

}
void deleteAfter(address Prec, address &P) {
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    //-------------your code here-------------
    P = next(Prec);
    next(Prec)= next(P);
    next(P)= NULL;
    //----------------------------------------
}
