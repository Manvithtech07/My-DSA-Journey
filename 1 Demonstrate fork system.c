/*1.Demonstrate fork() system call. Let the parent process display its pid, ppid and a message ‘I’m the parent’. Also let the child display its pid, ppid and a message ‘I’m the child’.*/
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		fprintf(stderr, "Fork Failed\n" );
		return 1;
	}
	else if(pid==0){
		printf("I am the child process\n");
		printf("Child's PID: %d\n",getpid());
		printf("Child's Parent PID (PPID): %d\n",getppid());
	}
	else{
		wait(NULL);
		printf("I am parent\n");
		printf("Parent PID: %d\n",getpid());
		printf("Parents Child's PID: %d\n",pid);
	}
	return 0;
}

/*2.*
Let the parent fork and let the child execute ls command. Observe the result with and without
having wait() system call in the parent.*/
#include<stdio.h>
#include<stdlib.h>//for exit()
#include<unistd.h>//for fork() execlp()
#include<sys/types.h>//for getpid() getppid()
#include<sys/wait.h>//for wait()
int main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		fprintf(stderr, "Fork failed\n");
		return 1;
	}else if(pid==0){
		printf("CHILD: I am the child, my PID: %d. I will run 'ls'\n",getpid());
		execlp("ls","ls",NULL);
		perror("execlp failed");
		exit(1);
	}else{
		printf("Parent: I am parent, my PID: %d. I am waiting for my child (PID %d) to finish \n",getpid(),pid);
		wait(NULL);
		printf("\nPARENT: My child has finished.\n");
	}
	return 0;
}

/*3.*
Let the parent create 4 children. Make them execute ls, ls –l, pwd and date commands. (One child executes one command.)*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	int status;
	printf("Parent PID %d starting\n",getpid());
	if((pid=fork())==0){
		//child 1
		printf("First child (PID %d) executes 'ls'\n",getpid());
		execlp("ls","ls",NULL);
		perror("execlp ls failed");
		exit(1);
	}
	wait(&status);
	if((pid=fork())==0){
		//child 2
		printf("Second child (PID %d) executes 'ls -l'\n",getpid());
		execlp("ls","ls","-l",NULL);
		perror("execlp ls -l failed");
		exit(1);
	}
	wait(&status);
	if((pid=fork())==0){
		//child 3
		printf("Third child (PID %d) executes 'pwd'\n",getpid());
		execlp("pwd","pwd",NULL);
		perror("execlp pwd failed");
		exit(1);
	}
	wait(&status);
	if((pid=fork())==0){
		//child 4
		printf("Fourth child (PID %d) executes 'date'\n",getpid());
		execlp("date","date",NULL);
		perror("execlp date failed");
		exit(1);
	}
	wait(&status);
	printf("\nParent: All 4 children have finished\n");
	return 0;
}

/*4.*
Create a child through fork(). Let the child generate the fibonacci series (1, 1, 2, 3, 5, 8…) upto n numbers. The value of n has to passed as a command line argument.*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
void fibonacci(int n){
	if(n<=0){
		return;
	}
	int a=0,b=1,nextTerm;
	printf("fibonacci series for %d terms\n",n);
	for(int i=1;i<=n;i++){
		printf("%d ",b);
		nextTerm = a + b;
		a = b;
		b = nextTerm;
	}
	printf("\n");
}
int main(int argc, char *argv[]){
	if(argc!=2){
		fprintf(stderr, "Error usage of terms%s\n",argv[0]);
		return 1;
	}
	int n = atoi(argv[1]);
	if(n<=0){
		fprintf(stderr, "Please enter a positive number.\n");
		return 1;
	}
	pid_t pid = fork();
	if(pid<0){
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if(pid==0){
		printf("CHILD PID %d. Fibonacci Series: \n",getpid());
		fibonacci(n);
		exit(0);
	}else{
		wait(NULL);
		printf("PARENT: Fibonacci series printed. \n");
	}
	return 0;
}


/*5.*Let the parent create a child using fork(). Let the parent geneate an odd series upto n numbers (1, 3, 5, 7, 9…) and let the child create an even series upto n numbers (0, 2, 4, 6, 8 …). (i) Pass the value of n as a command line argument. (ii) Read the value of n from the user.*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
//5.a
/*int main(int argc, char const *argv[])
{
	if(argc != 2){
		fprintf(stderr, "Error Usage of terms %s\n",argv[0]);
		return 1;
	}
	int n = atoi(argv[1]);
	if(n<=0){
		fprintf(stderr, "Enter a positive number\n");
		return 1;
	}
	pid_t pid = fork();
	if(pid<0){
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if(pid==0){
		printf("CHILD PID: %d. Series of even number:\n",getpid());
		for(int i=0;i<n;i++){
			printf("%d ",2*i);
		}
		exit(0);
	}else{
		wait(NULL);
		printf("\nPARENT: PID %d. Series of odd number:\n",getpid());
		for(int i=0;i<n;i++){
			printf("%d ", (2*i)+1);
	}
	printf("\nPARENT: Child has executed. Exiting\n");
}
	return 0;
}*/
//5.b
int main(){
	int n;
	printf("Enter number: \n");
	scanf("%d",&n);
	if(n<=0){
		fprintf(stderr, "Enter a positive number\n");
		return 1;
	}
	pid_t pid = fork();
	if(pid<0){
		fprintf(stderr, "Fork failed\n");
		return 1;
	}
	else if(pid == 0){
		printf("CHILD PID: %d. Series of even number:\n",getpid());
		for(int i=0;i<n;i++){
			printf("%d ",2*i);
		}
		exit(0);
	}else{
		wait(NULL);
		printf("\nPARENT: PID %d. Series of odd number:\n",getpid());
		for(int i=0;i<n;i++){
			printf("%d ", (2*i)+1);
	}
	printf("\nPARENT: Child has executed. Exiting\n");
}
	return 0;
}

/*QUESTION 7 7.
Let the parent create 2 children which work on a common sample file. Let one child count the
total number of lines in the file while the other counts the total number of characters in the same file.
Provide the filename as a command line argument.
#include<stdio.h>*/
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
	if(argc != 2){
		fprintf(stderr, "Error, \n");
		return 1;
	}
	int n = atoi(argv[1]);
	printf("CHILD PID %d. Even Series:\n",getpid());
	for(int i=0;i<n;i++){
		printf("%d ",2*i);
	}
	printf("\n");
	return 0;
}
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
	if(argc != 2){
		fprintf(stderr, "Error,%s \n", argv[0]);
		return 1;
	}
	int n_for_parent = atoi(argv[1]);
	if(n_for_parent<=0){
		fprintf(stderr, "Enter a positive number\n");
		return 1;
	}
	pid_t pid = fork();
	if(pid<0){
		fprintf(stderr, "Fork failed\n");
		return 1;
	}
	else if(pid ==0){
		printf("CHILD: PID %d. I will be replaced by even_generator.c\n",getpid());
		execlp("./even_generator","./even_generator",argv[1],NULL);
		perror("execlp failed");
		exit(1);
	}
	else{
		printf("PARENT (PID: %d): Printing odd series up to %d:\n", getpid(), n_for_parent);
        for (int i = 0; i < n_for_parent; i++) {
            printf("%d ", (2 * i) + 1); // 1, 3, 5, 7...
        }
        printf("\nPARENT: Done.\n");
        wait(NULL); 
        printf("PARENT: Child has finished. Parent is now exiting.\n");
    }

    return 0;
}

/*7.*Let the parent create 2 children which work on a common sample file. Let one child count the total number of lines in the file while the other counts the total number of characters in the same file. Provide the filename as a command line argument.*/
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
	if(argc != 2){
		fprintf(stderr, "Error,%s\n",argv[0]);
		return 1;
	}
	pid_t pid1,pid2;
	int status;
	printf("Parent PID %d starting\n",getpid());
	pid1 = fork();
	if(pid1<0){
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	if(pid1==0){
		printf("CHILD1 PID %d Total number of lines:\n",getpid());
		execlp("wc","wc","-l",argv[1],NULL);
		perror("execlp failed");
		exit(1);
	}
	waitpid(pid1, &status, 0);
	pid2 = fork();
	if(pid2<0){
		fprintf(stderr, "Fork failed\n");
		return 1;
	}
	if(pid2==0){
		printf("\nCHILD2 PID %d Total number of characters:\n",getpid());
		execlp("wc","wc","-c",argv[1],NULL);
		perror("execlp failed");
		exit(1);
	}
	waitpid(pid2, &status, 0);
	printf("\n--- Parent: Both children have finished. ---\n");
	return 0;
}



///question 8 Let the parent create 2 children which work on a common sample file. Let one child convert all lowercase to uppercase in the file while the other counts the total number of character ‘a’ s in the same file. Provide the filename as a command line argument.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>    // For toupper()

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];

    pid_t pid1, pid2;

    // --- Create Child 1 (Count 'a's) ---
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork 1 failed");
        return 1;
    }

    if (pid1 == 0) {
        // --- CHILD 1: 'a' Counter (Read-Only) ---
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("fopen read");
            exit(1);
        }

        int a_count = 0;
        int ch;
        while ((ch = fgetc(file)) != EOF) {
            if (ch == 'a') {
                a_count++;
            }
        }
        fclose(file);
        printf("CHILD 1 (Counter): Found %d 'a' characters.\n", a_count);
        exit(0);
    }

    // --- Create Child 2 (To Uppercase) ---
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork 2 failed");
        return 1;
    }

    if (pid2 == 0) {
        // --- CHILD 2: Uppercase (Read & Write) ---
        
        // 1. Read the whole file into a buffer (up to 4096 chars)
        char buffer[4096];
        FILE *file_read = fopen(filename, "r");
        if (file_read == NULL) {
            perror("fopen read");
            exit(1);
        }
        size_t bytes_read = fread(buffer, 1, 4095, file_read);
        buffer[bytes_read] = '\0'; // Null-terminate the string
        fclose(file_read);

        // 2. Modify the buffer
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        
        // 3. Write the buffer back, overwriting the file
        FILE *file_write = fopen(filename, "w");
        if (file_write == NULL) {
            perror("fopen write");
            exit(1);
        }
        fprintf(file_write, "%s", buffer);
        fclose(file_write);

        printf("CHILD 2 (Converter): Converted file to uppercase.\n");
        exit(0);
    }

    // --- PARENT PROCESS ---
    // Wait for both children to finish
    wait(NULL);
    wait(NULL);
    
    printf("PARENT: Both children have finished.\n");
    return 0;
}




///9.*Let the parent create 2 children which work on a common sample file. Let one child count the total number of words in the file. Let the other child invert the case of alphabets in the file. Provide the filename as a command line argument.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>    // For islower(), isupper(), toupper(), tolower()

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];

    pid_t pid1, pid2;

    // --- Create Child 1 (Word Count using 'wc -w') ---
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork 1 failed");
        return 1;
    }

    if (pid1 == 0) {
        // --- CHILD 1: Word Counter ---
        printf("CHILD 1 (Counter): Counting words...\n");
        execlp("wc", "wc", "-w", filename, NULL);
        perror("execlp wc failed"); // Only runs if exec fails
        exit(1);
    }

    // --- Create Child 2 (Invert Case) ---
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork 2 failed");
        return 1;
    }

    if (pid2 == 0) {
        // --- CHILD 2: Case Inverter (Read & Write) ---
        // This logic is just like Q8
        
        // 1. Read file into a buffer
        char buffer[4096];
        FILE *file_read = fopen(filename, "r");
        if (file_read == NULL) {
            perror("fopen read");
            exit(1);
        }
        size_t bytes_read = fread(buffer, 1, 4095, file_read);
        buffer[bytes_read] = '\0';
        fclose(file_read);

        // 2. Modify buffer (invert case)
        for (int i = 0; i < bytes_read; i++) {
            if (islower(buffer[i])) {
                buffer[i] = toupper(buffer[i]);
            } else if (isupper(buffer[i])) {
                buffer[i] = tolower(buffer[i]);
            }
        }
        
        // 3. Write buffer back to file
        FILE *file_write = fopen(filename, "w");
        if (file_write == NULL) {
            perror("fopen write");
            exit(1);
        }
        fprintf(file_write, "%s", buffer);
        fclose(file_write);

        printf("CHILD 2 (Converter): Inverted file case.\n");
        exit(0);
    }

    // --- PARENT PROCESS ---
    // Wait for both children to finish
    wait(NULL);
    wait(NULL);
    
    printf("PARENT: Both children have finished.\n");
    return 0;
}




----------------------------------------------------------------------------------Threads--------------------------------------------------------------------------------------------


/*4. *Create two threads in a main program, let the first thread execute a
function to display a message namely “this is thread one” , similarly let the second thread displays “this is thread two’.*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *print_message_function(void*ptr){
	char *message = (char*)ptr;
	printf("%s\n",message);
	return NULL;
}
int main(){
	pthread_t thread1,thread2;
	char *message1 = "I am thread1";
	char *message2 = "I am thread2";
	pthread_create(&thread1,NULL,print_message_function,(void*)message1);
	pthread_create(&thread2,NULL,print_message_function,(void*)message2);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}





/*5. *Create a common shared memory area where in one thread writes a
string termed “Hello There”; the second thread reads the string and
displays it on the screen. Also the second string converts all lower case to
upper case and vice versa in the shared memory. Next the first thread will
read this from the shared memory and will output the same to the screen.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pthread.h>
char shared_buffer[100];
pthread_mutex_t lock;
int flag1_ready = 0;
int flag2_modified = 0;
void *thread_one(void *arg){
    pthread_mutex_lock(&lock);
    strcpy(shared_buffer,"Hello There");
    printf("Thread1: Wrote Hello There\n");
    flag1_ready=1;
    pthread_mutex_unlock(&lock);
    while(flag2_modified==0){}
    pthread_mutex_lock(&lock);
    printf("Thread1: Read modified %s\n",shared_buffer);
    pthread_mutex_unlock(&lock);
    return NULL;
}
void *thread_two(void *arg){
    while(flag1_ready==0){}
    pthread_mutex_lock(&lock);
    printf("Thread2: Read %s\n",shared_buffer);
    for(int i=0;shared_buffer[i]!='\0';i++){
        if(islower(shared_buffer[i]))
            shared_buffer[i]=toupper(shared_buffer[i]);
        else if(isupper(shared_buffer[i]))
            shared_buffer[i]=tolower(shared_buffer[i]);
    }
    printf("Thread2: Modified %s\n",shared_buffer);
    flag2_modified=1;
    pthread_mutex_unlock(&lock);
    return NULL;

}
int main(){
    pthread_t thread1,thread2;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&thread1,NULL,thread_one,NULL);
    pthread_create(&thread2,NULL,thread_two,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}



/*7. *Next create a common shared memory area where in one thread writes a sequence of numbers, the second thread reads the numbers, calculates their sum and displays the result to the screen.*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define SIZE 5
int shared_buffer[SIZE];
pthread_mutex_t lock;
int data_ready=0;

void *thread_one(void*arg){
	pthread_mutex_lock(&lock);
	printf("Thread1: Writing sequence of numbers: \n");
	for(int i=0;i<SIZE;i++){
		shared_buffer[i]=i+1;
		printf("%d ",shared_buffer[i]);
	}
	data_ready=1;
	pthread_mutex_unlock(&lock);
	return NULL;
}
void *thread_two(void *arg){
	while(data_ready==0 ){}
	pthread_mutex_lock(&lock);
	int sum=0;
	printf("\nThread2: Reading sequence of numbers\n");
	for(int i=0;i<SIZE;i++){
		sum = sum + shared_buffer[i];
		printf("%d ",shared_buffer[i]);
	}
	printf("\nSum: %d\n",sum);
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(){
	pthread_t thread1,thread2;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&thread1,NULL,thread_one,NULL);
	pthread_create(&thread2,NULL,thread_two,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}



/*8. *Declare a matrix of size m x n , and populate it. (Fill it) Create m threads such that each thread calculates the ith row sum. Let the main thread display each row sum result as well as the total sum.*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define M 
#define N 4

int matrix[M][N];
int row_sums[M];

void *calculate_row_sum(void *arg){
	int row = *(int*)arg;
	int sum = 0;
	for(int j=0;j<N;j++){
		sum = sum + matrix[row][j];
	}
	row_sums[row]=sum;
	return NULL;
}

int main(){

	//1.populate matrix
	int count = 1;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			matrix[i][j] = count++;
		}
	}

	//2.prepare for thread creation
	pthread_t threads[M];
	int thread_args[M];
	for(int i=0;i<M;i++){
		thread_args[i]=i;
		pthread_create(&threads[i],NULL,calculate_row_sum,(void*)&thread_args[i]);

	}

	for(int i=0;i<M;i++){
		pthread_join(threads[i],NULL);
	}

	int total_sum=0;
	for(int i=0;i<M;i++){
		printf("Row %d sum: %d\n",i,row_sums[i]);
		total_sum = total_sum + row_sums[i];
	}
	printf("Total matrix sum: %d\n",total_sum);
	return 0;
}





/*9. *create and save a sample text (a file containing any text) in your current
working directory . Next write a program which creates two threads such
that one thread counts the total number of words present in the file and
the other thread changes all upper case characters to lower case.
10.*Modify the above program to create a third thread too; the third thread
writes “three threads have visited this file” at the very end of the file.*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>

#define FILENAME "sample.txt"

// Thread function declarations
void *count_words(void *arg);
void *convert_to_lowercase(void *arg);
void *append_message(void *arg);

// Global mutex for file access synchronization
pthread_mutex_t file_lock;

int main()
{
    pthread_t t1, t2, t3;
    pthread_mutex_init(&file_lock, NULL);

    // Create threads
    pthread_create(&t1, NULL, count_words, NULL);
    pthread_create(&t2, NULL, convert_to_lowercase, NULL);

    // Wait for both threads to finish before creating third one
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Create and run third thread
    pthread_create(&t3, NULL, append_message, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&file_lock);
    return 0;
}


// Thread 1: Count total number of words in the file
void *count_words(void *arg)
{
    pthread_mutex_lock(&file_lock);
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("Error opening file");
        pthread_mutex_unlock(&file_lock);
        pthread_exit(NULL);
    }

    int count = 0;
    char word[100];

    // while (fscanf(fp, "%99s", word) == 1)
    //     count++;


    int words = 0;
    char ch, prev = ' ';
    while ((ch = fgetc(fp)) != EOF) {
        if (isspace(ch) && !isspace(prev)) {
            words++;
        }
        prev = ch;
    }
    // If the file doesn't end with space, count the last word
    if (!isspace(prev)) {
        words++;
    }
    fclose(fp);
    pthread_mutex_unlock(&file_lock);

    printf("Thread 1: Total words in the file = %d\n", words);
    pthread_exit(NULL);
}


// Thread 2: Convert all uppercase letters to lowercase
void *convert_to_lowercase(void *arg)
{
    pthread_mutex_lock(&file_lock);
    FILE *fp = fopen(FILENAME, "r+");
    if (fp == NULL) {
        perror("Error opening file");
        pthread_mutex_unlock(&file_lock);
        pthread_exit(NULL);
    }

    char ch;
    long pos;

    while ((ch = fgetc(fp)) != EOF) {
        if (isupper(ch)) {
            pos = ftell(fp);
            fseek(fp, pos - 1, SEEK_SET);
            fputc(tolower(ch), fp);
        }
    }

    fclose(fp);
    pthread_mutex_unlock(&file_lock);

    printf("Thread 2: Converted all uppercase characters to lowercase.\n");
    pthread_exit(NULL);
}

// Thread 3: Append message to the end of the file
void *append_message(void *arg)
{
    pthread_mutex_lock(&file_lock);
    FILE *fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        perror("Error opening file");
        pthread_mutex_unlock(&file_lock);
        pthread_exit(NULL);
    }

    fprintf(fp, "\nthree threads have visited this file\n");
    fclose(fp);
    pthread_mutex_unlock(&file_lock);

    printf("Thread 3: Appended message to the file.\n");
    pthread_exit(NULL);
}



// Design a thread program which recurcively creates threads in the thread function. Print the thread number in the function.The number of recursive calls are input from the keyboard 
#include<stdio.h>
#include<pthread.h>
void *recursive_thread(void *arg){
	int n = *(int*)arg;
	if(n<=0){
		return NULL;
	}
	pthread_t thread;
	n=n-1;
	printf("Thread %d Created.\n",n);
	pthread_create(&thread,NULL,recursive_thread,(void*)&n);
	pthread_join(thread,NULL);
	printf("Thread %d Exiting\n",n+1);
	return NULL;
}
int main(){
	int n;
	printf("Enter the number of recursive calls:\n");
	scanf("%d",&n);
	pthread_t thread;
	pthread_create(&thread, NULL, recursive_thread, (void*)&n);
	pthread_join(thread,NULL);
	printf("All threads finished\n");
	return 0;

}



////Recursive fork
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include<sys/wait.h>


void recursive_fork(int n) {
    if (n <= 0)
        return;

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        // Child process
        printf("Child process created: PID = %d, PPID = %d\n", getpid(), getppid());
        recursive_fork(n - 1);  // Recursive call in the child
        exit(0);
    } 
    else {
        // Parent waits for child
        wait(NULL);
        printf("Parent process (PID = %d) finished waiting.\n", getpid());
    }
}

int main() {
    int n;
    printf("Enter the number of recursive forks: ");
    scanf("%d", &n);

    printf("Main process PID: %d\n", getpid());
    recursive_fork(n);

    printf("Main process exiting.\n");
    return 0;
}

