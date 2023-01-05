#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

// Declaration of all the functions used for caeser
void Caeser_Encryption_DK (char plain_text[]);
void Caeser_Decryption_DK (char encrypted_text[]);

void Caeser_Encryption_CK (int n);
void Caeser_Decryption_CK (int n);

void Casear_Cryptography ();

// Declaration of all the functions used for mono alphabetic
void Monoalpha_Encryption_DK ();
void Monoalpha_Encryption_CK ();
void monoalpha_encryption ();

void Monoalpha_Decryption_DK ();
void Monoalpha_Decryption_CK ();
void monoalpha_decryption ();

void Monoalpha_Cryptography ();

void login_signup();
void cryptography();

struct entry
{
    char name[BUFSIZ], dob[BUFSIZ], age[BUFSIZ], mob[BUFSIZ], email[BUFSIZ];
} s;

int main ()
{
    login_signup ();
    cryptography ();

    return 0;
}

void login_signup ()
{
    FILE *f1, *f2, *f3;
    int ch, chk = 0, i = 0;
    char ent, name[12], path[16], pass[12], check_pass[12], check_name[12];

    system("cls");
    printf("\n\n\n\n\n\t\t\t\t|--------------------------------------|\n");
    printf("\t\t\t\t|        [  Crypto Engine  ]           |\n");
    printf("\t\t\t\t|======================================|\n");
    printf ("How you want to continue?");
    printf("\n1. Sign Up ");
    printf("\n2. Log In\n");
    scanf("%d",&ch);

    switch(ch) {
        case 1:
	        A :
	        system("cls");
            f1 = fopen("ids.txt","a+");
            f2 = fopen("passwords.txt","a+");
            rewind(f1);

            printf("\nEnter Username: ");
            fflush(stdin);
            gets(check_name);

            while (fscanf(f1, "%s", &name) != EOF) {
	            if (strcmp(name, check_name) == 0) {
	                system("cls");
                    printf("Username already exists... Please try another one...");
                    getch();
                    fclose(f1);
                    goto A;
	            }
	        }

	        printf("Enter your Password: ");
	        while (1) {
	            ent = getch ();
	            if (ent == 13) {
                    pass[i] = '\0';
                    break;
	            }

	            else if (ent == 8) {
	                i--;
	                printf("\b \b");
	                continue;
	            }

	            else {
	                pass[i] = ent;
	                i++;
	                printf("*");
	            }
	        }
            strcpy(name, check_name);
            fprintf(f1, "%s \n", &name);
            fprintf(f2, "%s \n", &pass);

            strcpy(path, name);
            strcat(path, ".txt");
            f3 = fopen(path, "w");
            system("cls");

            printf("Enter your name: ");
            fflush(stdin);
            gets(s.name);

            printf("Enter your date of birth (dd/mm/yyyy): ");
            fflush(stdin);
            gets(s.dob);

            printf("Enter your age: ");
            fflush(stdin);
            gets(s.age);

            printf("Enter your mobile number: ");
            fflush(stdin);
            gets(s.mob);

            printf("Enter your email address: ");
            fflush(stdin);
            gets(s.email);
            fprintf(f3, "%s\n%s\n%s\n%s\n%s\n%s\n",s.name, s.dob, s.age, s.mob, s.email);
            fclose(f3);
            system("cls");

            printf("\n\n\t\t\t\t\t.....Registration Successful.....\n");
            rewind(f1);
            rewind(f2);
            break;
        case 2:
	        B:
            system("cls");
            f1 = fopen("ids.txt", "a+");
            f2 = fopen("passwords.txt", "a+");
            rewind(f1);
            rewind(f2);

            printf("\nEnter Username: ");
            fflush(stdin);
            gets(check_name);

            printf("Enter your password: ");
            fflush(stdin);
            while (1) {
	            ent = getch();
	            if (ent == 13) {
                    check_pass[i] = '\0';
                    break;
	            }

                else if (ent == 8) {
	                i--;
                    printf("\b \b");
                    continue;
	            }

                else {
                    check_pass[i] = ent;
                    i++;
                    printf("*");
	            }
	        }
	        while (fscanf(f1, "%s", &name) != EOF) {
                fscanf(f2, "%s", &pass);
                if(strcmp(name, check_name) == 0 && strcmp(pass, check_pass) == 0) {
                    chk=1;
                    break;
	            }

                else continue;
	        }
	        if (chk == 1) {
                system("cls");

                printf("Yay!!! Login Successful... Click to Continue ");
                strcpy(path, name);
                strcat(path, ".txt");
                f3 = fopen(path, "r");

                system("cls");
                fgets(s.name, BUFSIZ, f3);
                fgets(s.dob, BUFSIZ, f3);

                fgets(s.age, BUFSIZ, f3);
                fgets(s.mob, BUFSIZ, f3);
                fgets(s.email, BUFSIZ, f3);

                printf("\t\t\t\t|==========================================|\n");
                printf("\t\t\t\t|......WELCOME BACK TO YOUR PROFILE........|\n");
                printf("\t\t\t\t|==========================================|\n");
                printf("");

                printf("\nName: ");
                puts(s.name);

                printf("Date Of birth: ");
                puts(s.dob);

                printf("Age: ");
                puts(s.age);

                printf("Mobile number: ");
                puts(s.mob);

                printf("Email: ");
                puts(s.email);
                fclose(f1);
                fclose(f2);
                fclose(f3);
	        }

            else if (chk == 0) {
                system("cls");
                printf("Invalid Password or username");

                fclose(f1);
                fclose(f2);
                exit(0);
	        }

            else {
	            system("cls");
                printf("OOPS SOMETHING WENT WRONG...TRY AGAIN LATER");
	        }

	    break;
    }
}

void cryptography ()
{
    char cryp_type;
    printf("\t\t\t\t|==========================================|\n");
    printf("\t\t\t\t|..........Welcome to Cypto Engine.........|\n");
    printf("\t\t\t\t|==========================================|\n");

    printf ("\n\n\t\t\t Which cryptography process you want to do? \n\t\t\t 1. Caesar \n\t\t\t 2. Mono-alphabetic");
    printf ("\n\n\t\t\tPress 'C' for casesar and 'M' for Mono-alphabetic\n\t\t\t");

    scanf ("%c", &cryp_type);
    cryp_type = toupper(cryp_type);


    switch (cryp_type) {
        case 'C':
            Casear_Cryptography();
            break;

        case 'M':
            Monoalpha_Cryptography();
            break;
    }
}

void Caeser_Encryption_DK (char plain_text[])
{
    int i, key = 7;     // Setting a default key
    char ch;
    for (i = 0; plain_text[i] != '\0'; ++i) {
        ch = plain_text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            plain_text[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            plain_text[i] = ch;
        }
    }
}

void Caeser_Decryption_DK (char encrypted_text[])
{
    int i, key = 7;     // Setting a default key
    char ch;
    for (i = 0; encrypted_text[i] != '\0'; ++i) {
        ch = encrypted_text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            encrypted_text[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            encrypted_text[i] = ch;
        }
    }
}

 void Caeser_Encryption_CK (int n)
 {
    char plain_text[100], ch;
	int i, key;
	system("cls");// clear console

    if (n == 1) {
        printf("Enter your message to encrypt = ");

        getchar();
        gets(plain_text);
        Caeser_Encryption_DK(plain_text);
    }

    else if (n == 2) {
        printf("Enter your message to encrypt = ");

        getchar();
        gets(plain_text);
        printf("\n\t\t\t Please enter your key within 1 to 10 = ");

        scanf("%d", &key);

        for (i = 0; plain_text[i] != '\0'; ++i) {
            ch = plain_text[i];

            if (ch >= 'a' && ch <= 'z') {
                ch = ch + key;

                if (ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }

                plain_text[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;

                if(ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                plain_text[i] = ch;
            }
        }
	}

	printf("\n\t\t\tEncrypted message = %s\n", plain_text);
}

void Caeser_Decryption_CK (int n)
{
    char encrypted_text[100], ch;
	int i, key;
	system("cls");

    if (n == 1) {
        printf("Enter your message to decrypt = ");

        getchar();
        gets(encrypted_text);

        Caeser_Decryption_DK(encrypted_text);
    }

    else if (n == 2) {
        printf("Enter your message to decrypt = ");

        getchar();
        gets(encrypted_text);

        printf("\n\t\t\t Please enter your key within 1 to 10 = ");
        scanf("%d", &key);

        for (i = 0; encrypted_text[i] != '\0'; ++i) {
            ch = encrypted_text[i];

            if (ch >= 'a' && ch <= 'z') {
                ch = ch - key;

                if(ch < 'a') {
                    ch = ch + 'z' - 'a' + 1;
                }
                encrypted_text[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch - key;

                if(ch < 'A') {
                    ch = ch + 'Z' - 'A' + 1;
                }
                encrypted_text[i] = ch;
            }
        }
    }

	printf("\n\t\t\tDecrypted message = %s\n", encrypted_text);
}

void Casear_Cryptography ()
{
    char option;
    int n;
    fun:

    printf("\n\n\t\t\t Please enter 'E' to encrypt or 'D' to decrypt\n\t\t\t");
    getchar();
    scanf("%c", &option);

    option = toupper(option);     // Changing into uppercase if entered as lowercase
    switch(option) {
        case 'E':
            printf("\n\t\t\t 1. Default Key\n\t\t\t");
            printf("\n\t\t\t 2. Customize Key\n\n\t\t\t");
            printf("\n\t\t\t Please choose a key type \n\t\t\t");

            printf("\n\t\t\t Your choice : ");
            scanf("%d", &n);

            Caeser_Encryption_CK(n);
            break;
        case 'D':
            printf("\n\t\t\t 1. Default Key\n\t\t\t");
            printf("\n\t\t\t 2. Customize Key\n\n\t\t\t");
            printf("\n\t\t\t Please choose a key type \n\t\t\t");

            printf("\n\t\t\t Your choice : ");
            scanf("%d", &n);

            Caeser_Decryption_CK(n);
            break;
        default:
            printf("\n\t\t\tOops!! Wrong key word!! Try again..");
    }
}

void Monoalpha_Encryption_DK ()
{
    char pt[] = {'A','B','C','D','E','F','G','H','I','J','K',

                 'L','M','N','O','P','Q','R','S','T','U','V',

                  'W','X','Y','Z','a','b','c','d','e','f','g','h',

                   'i','j','k','l','m','n','o','p','q','r','s','t',

                   'u','v','w','x','y','z',' '};

    char ct[] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O',

                 'N','M','L','K','J','I','H','G','F','E','D','C',

                  'B','A','z','y','x','w','v','u','t','s','r','q',

                  'p','o','n','m','l','k','j','i','h','g','f',

                  'e','d','c','b','a',' '};

    char p[100], c[100], r[100];

    int i, j;

    system("cls");
    printf("\nEnter your message to encrypt = ");

    gets(p);
    int len = strlen(p);

    for (i = 0; i < len; i++) {
        for (j = 0; j < 53; j++) {
            if (pt[j] == p[i]) {
                c[i] = ct[j];
            }
        }
    }
    c[i]='\0';
    printf("\nThe encrypted text =  %s\n", c);
}

void Monoalpha_Encryption_CK ()
{
    char pt[] = {"abcdefghijklmnopqrstuvwxyz "};
    // Sequnence of the English alphabet
    char ct[27];
    // key
    printf("\n Please enter your 26 alphabatic key in lower case & a space: \n");

    for (int i = 0; i < 27; i++) {
        ct[i] = getch();
        printf("%c ", ct[i]);
    }

    char p[100];    //use for input plain text
    char c[100];    //use for output e
    int i, j;

    system("cls");
    printf("\n\n Enter your message to encrypt =  ");
    gets(p);

    for (i = 0; i < strlen(p); i++) {
        for (j = 0; j < 27; j++) {
            if (pt[j] == p[i]) {
                c[i] = ct[j];
            }
        }
    }
    c[i]='\0';
    printf("\n The encrypted text = %s\n", c);
}

void monoalpha_encryption ()
{
    int ch;

    printf("\n\t\t\t 1. Default Key\n\t\t\t");
    printf("\n\t\t\t 2. Customize Key\n\n\t\t\t");
    printf("\n\t\t\t Please choose a key type \n\t\t\t");

    printf("\n\t\t\t Your choice : ");
    scanf("%d", &ch);

    getchar();
    switch(ch) {
        case 1:
            Monoalpha_Encryption_DK();
            break;
        case 2:
            Monoalpha_Encryption_CK();
            break;
    }
}

void Monoalpha_Decryption_DK ()
{
    char pt[] = {'A','B','C','D','E','F','G','H','I','J','K',

                 'L','M','N','O','P','Q','R','S','T','U','V',

                  'W','X','Y','Z','a','b','c','d','e','f','g','h',

                   'i','j','k','l','m','n','o','p','q','r','s','t',

                   'u','v','w','x','y','z',' '};

    char ct[] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O',

                 'N','M','L','K','J','I','H','G','F','E','D','C',

                  'B','A','z','y','x','w','v','u','t','s','r','q','p','o',

                'n','m','l','k','j','i','h','g','f','e','d','c','b','a',' '};

    char c[100], r[100];

    int i, j;

    system("cls");
    printf("\n Enter your message to decrypt = ");

    getchar();
    gets(c);

    for (i = 0; i < strlen(c); i++) {
        for (j = 0; j < 53; j++) {
            if (ct[j] == c[i]) {//
                r[i] = pt[j];
            }
        }
    }
    r[i]='\0';
    printf("\nThe decrypted text = %s\n",r);
}
void Monoalpha_Decryption_CK ()
{
    char pt[] = {"abcdefghijklmnopqrstuvwxyz "};
    char ct[27];

    system("cls");
    printf("\nPlease enter your 26 alphabatic key  in lower case & a space: \n");
    for(int i = 0; i < 27; i++) {
        ct[i] = getch();
        printf("%c ", ct[i]);
    }

    char c[100];    //use for input plain text
    char r[100];    //use for output decrypted text
    int i, j;

    system("cls");
    printf("\n\n Enter your message to decrypt =  ");
    getchar();
    gets(c);

    for (i = 0; i < strlen(c); i++) {
        for (j = 0; j < 27; j++) {
            if (ct[j] == c[i]) {
                r[i] = pt[j];
            }
        }
    }
    r[i]='\0';
    printf("\nThe decrypted text = %s\n",r);
}
void monoalpha_decryption ()
{
    int ch;

    printf("\n\t\t\t 1. Default Key\n\t\t\t");
    printf("\n\t\t\t 2. Customize Key\n\n\t\t\t");
    printf("\n\t\t\t Please choose a key type \n\t\t\t");

    printf("\n\t\t\t Your choice : ");
    scanf("%d", &ch);

    switch(ch) {
        case 1:
            Monoalpha_Decryption_DK();
            break;
        case 2:
            Monoalpha_Decryption_CK();
            break;
    }
}
void Monoalpha_Cryptography ()
{
    char ch;

    printf("\n\n\t\t\t Please enter 'E' to encrypt or 'D' to decrypt\n\t\t\t");
    getchar();

    scanf("%c",&ch);
    switch(ch) {
        case 'E':
        case 'e':
            monoalpha_encryption();
            break;

        case 'D':
        case 'd':
            monoalpha_decryption();
            break;
    }
}