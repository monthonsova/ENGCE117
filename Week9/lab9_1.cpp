#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

class LinkedList {
    protected :
        struct studentNode *start, **now ;
    public :
        LinkedList() {
            start = NULL ;
            now = &start ;
        }
        ~LinkedList() {
            struct studentNode *temp ;
            while( start != NULL ) {
                temp = start ;
                start = start->next ;
                delete temp ;
            }
        }
        void InsNode( char n[], int a, char s, float g ) {
            struct studentNode *newNode = new struct studentNode ;
            strcpy( newNode->name, n ) ;
            newNode->age = a ;
            newNode->sex = s ;
            newNode->gpa = g ;
            newNode->next = *now ;
            *now = newNode ;
        }
        void DelNode() {
            if( *now == NULL ) return ;
            struct studentNode *temp = *now ;
            *now = (*now)->next ;
            delete temp ;
        }
        void GoNext() {
            if( *now != NULL ) {
                now = &((*now)->next) ;
            }
        }
        void GoFirst() {
            now = &start ;
        }
        void GoLast() {
            GoFirst() ;
            while( *now != NULL ) {
                now = &((*now)->next) ;
            }
        }
        void ShowAll() {
            struct studentNode *temp = start ;
            while( temp != NULL ) {
                printf( "%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa ) ;
                temp = temp->next ;
            }
        }
        int FindNode( char n[] ) {
            GoFirst() ;
            while( *now != NULL ) {
                if( strcmp( (*now)->name, n ) == 0 ) return 1 ;
                GoNext() ;
            }
            return 0 ;
        }
        struct studentNode *NowNode() {
            return *now ;
        }
        void EditNode( char n[], int a, char s, float g ) {
            if( *now != NULL ) {
                strcpy( (*now)->name, n ) ;
                (*now)->age = a ;
                (*now)->sex = s ;
                (*now)->gpa = g ;
            }
        }
} ;

void AddData( LinkedList *ll ) {
    char n[20], s ;
    int a ;
    float g ;
    printf( "   Enter Name Age Sex GPA: " ) ;
    scanf( "%s %d %c %f", n, &a, &s, &g ) ;
    ll->GoLast() ;
    ll->InsNode( n, a, s, g ) ;
}

void EditData( LinkedList *ll ) {
    char n[20], s ;
    int a ;
    float g ;
    printf( "   Enter name to edit: " ) ;
    scanf( "%s", n ) ;
    if( ll->FindNode( n ) ) {
        printf( "   Enter New Data (Name Age Sex GPA): " ) ;
        scanf( "%s %d %c %f", n, &a, &s, &g ) ;
        ll->EditNode( n, a, s, g ) ;
    } else {
        printf( "   Name not found.\n" ) ;
    }
}

void FindData( LinkedList *ll ) {
    char n[20] ;
    printf( "   Enter name to find: " ) ;
    scanf( "%s", n ) ;
    if( ll->FindNode( n ) ) {
        struct studentNode *temp = ll->NowNode() ;
        printf( "   Found: %s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa ) ;
    } else {
        printf( "   Not found.\n" ) ;
    }
}

void readfile( LinkedList *ll ) {
    FILE *fp = fopen( "student.txt", "r" ) ;
    if( fp == NULL ) return ;
    char n[20], s ;
    int a ;
    float g ;
    while( fscanf( fp, "%s %d %c %f", n, &a, &s, &g ) != EOF ) {
        ll->GoLast() ;
        ll->InsNode( n, a, s, g ) ;
    }
    fclose( fp ) ;
}

void writefile( LinkedList *ll ) {
    FILE *fp = fopen( "student.txt", "w" ) ;
    if( fp == NULL ) return ;
    ll->GoFirst() ;
    struct studentNode *temp ;
    while( ( temp = ll->NowNode() ) != NULL ) {
        fprintf( fp, "%s %d %c %.2f\r\n", temp->name, temp->age, temp->sex, temp->gpa ) ;
        ll->GoNext() ;
    }
    fclose( fp ) ;
}

int main() {
    LinkedList listA ;
    int menu ;
    readfile( &listA ) ;
    printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : " ) ;
    scanf( "%d", &menu ) ;
    while( menu != 0 ) {
        switch( menu ) {
            case 1 : AddData( &listA ) ; break ;
            case 2 : EditData( &listA ) ; break ;
            case 3 : {
                char n[20] ;
                printf( "   Enter name to delete: " ) ;
                scanf( "%s", n ) ;
                if( listA.FindNode( n ) ) listA.DelNode() ;
                break ;
            }
            case 4 : FindData( &listA ) ; break ;
            case 5 : listA.ShowAll() ; break ;
        }
        printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : " ) ;
        scanf( "%d", &menu ) ;
    }
    writefile( &listA ) ;
    return 0 ;
}