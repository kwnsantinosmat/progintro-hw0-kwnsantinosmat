#include <stdio.h>

int main() {

    char eidos;                 //Η μεταβλητή eidos δείχνει πώς θα τυπωθεί η ακολουθία aliquot.

    long long arithmos;         //Στην μεταβλητή arithmos ο χρήστης εισάγει τον αριθμό από τον οποίο θα ξεκινήσει η ακολουθία aliquot.

    long long epanalipseis=0;         // Η μεταβλητή epanalipseis δείχνει πόσες επαναλήψεις έχουν γίνει

    long long max_epanalipseis; // Στη μεταβλητή max_epanalipseis ο χρήστης εισάγει τον αριθμό που καθορίζει το όριο των επαναλήψεων

    long long i;                      // Η μεταβλητή i χρησιμοποιείται στη for

    printf("Please give the number to start the aliquot sequence from:");

    scanf("%lld", &arithmos);   // Εδώ ο χρήστης εισάγει την μεταβλητή arithmos και στη συνέχεια γίνεται έλεγχος εγκυρότητας

    if (arithmos>1000000000000000 || arithmos<0){

        printf("Number exceeds maximum supported integer (1000000000000000). Stopping.");

        return 1;

    }

    printf("Provide the max aliquot length to look for (0 for unlimited):");
                                // Εδώ ο χρήστης εισάγει την μεταβλητή max_epanalipseis και στη συνέχεια γίνεται έλεγχος εγκυρότητας
    scanf("%lld", &max_epanalipseis); 

    if (max_epanalipseis>1000000000000000 || max_epanalipseis<0){

        printf("Number exceeds maximum supported integer (1000000000000000). Stopping.");

        return 1;

    }
    int c;
                                // Εδώ γίνεται καθαρισμός του buffer, στη συνέχεια εισάγεται ο τρόπος εμφάνισης του αποτελέσματος και τέλος γίνεται έλεγχος εγκυρότητας
    while ((c = getchar()) != '\n' && c != EOF);  

    printf("Do you want to print the full sequence ('f') or just the length ('l')?");

    eidos = getchar();

    if (!(eidos=='f') && !(eidos=='l')){

        return 1;

    }
    if (eidos=='f'){
    printf("%lld\n", arithmos);
    }   
                            // Εδώ ξεκινά η διαδικασία της aliquot   
    while( 1 ){
                            // Εδώ μηδενίζεται η μεταβλητή sum ώστε να επαναχρησιμοποιηθεί στην επανάληψη
        long long sum=0;
                            // Αυτή είναι η συνάρτηση aliquot
        for (i=1; i<=arithmos/2; i++){

            if(arithmos%i==0){
        
                sum+=i;

            };
        
        }
        epanalipseis+=1;
                            // Εδώ γίνεται έλεγχος για το αν ξεπεράστηκε το όριο του υποστηριζόμενου ακέραιου
        if (epanalipseis>1000000000000000){

            printf("Number exceeds maximum supported integer (1000000000000000). Stopping.");

            return 1;

        }
        if (sum>1000000000000000 || sum<0){

            printf("Number exceeds maximum supported integer (1000000000000000). Stopping.");
        
            return 1;
        }
        arithmos=sum;
                            // Εδώ γίνονται οι εμφανίσεις αν ο χρήστης έχει εισάγει το γράμμα 'f' στο eidos
        if (eidos=='f'){

            printf("%lld\n",sum) ;

        }
                            // Εδώ γίνονται οι έλεγχοι για το αν πρέπει να βγει από την επανάληψη while
        if (arithmos == 0) break;

        if (epanalipseis>=max_epanalipseis && max_epanalipseis!=0){ 

            break;
        }
  
    
    };
                            // Εδώ γίνονται οι εμφανίσεις αν ο χρήστης έχει εισάγει το γράμμα 'l' στο eidos
    if (eidos=='l'){

        printf("%lld\n",epanalipseis) ;

    }

    return 0;

}