#include <sys/types.h>

#include <sys/wait.h>

#include <stdio.h>

#include <stdlib.h>

#include <iostream>

#include <unistd.h>



using namespace std;



int main() {

    pid_t pid;



    int n;



    cout << "please enter a positive integer" << endl;

    cin >> n;



    pid = fork();





    if (n <= 0) {

        fprintf(stderr, "Negative Integer\n");

        return 1;

    }



    if (pid < 0) {

        fprintf(stderr, "Fork Failed\n");

        return 1;

    }



    else if (pid == 0) {

        execlp("/bin/ls\n", "ls\n", NULL);

        while (n > 1) {

            if (n % 2 == 0) {

                n = n / 2;

                cout << n << endl;

            }

            else {

                n = (3 * n) + 1;

                cout << n << endl;

            }

        }

    }



    else {

        wait(NULL);

        printf("Child Complete\n");

    }

}