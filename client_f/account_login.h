
#define PASS_LENGTH 30

int mytrain(int sock);
int user_menu(int sock, int type);
int do_admin_action(int sock, int action);
int do_action(int sock, int opt);
int view_booking(int sock);

int account_login(int opt,int  sock){
	if(opt==1){
		int type, acc_no;
		char password[PASS_LENGTH];
		printf("Enter account type:\n");
		printf("1. Customer\n2. Agent\n3. Admin\n");
		printf("Your Response: ");
		scanf("%d", &type);
		printf("Enter Your Account Number: ");
		scanf("%d", &acc_no);
		strcpy(password,getpass("Enter the password: "));

		write(sock, &type, sizeof(type));
		write(sock, &acc_no, sizeof(acc_no));
		write(sock, &password, strlen(password));

		int valid_login;
		read(sock, &valid_login, sizeof(valid_login));
		if(valid_login == 1){
			while(user_menu(sock, type)!=-1); //calling user_menu
			system("clear");
			return 1;
		}
		else{
			printf("Login Failed : Multiple Login for this user is not allowed.\n");
			while(getchar()!='\n');
			getchar();
			return 1;
		}
	}
	else if(opt==2){
		int type, acc_no;
		char password[PASS_LENGTH], secret_pin[5], name[10];
		printf("Enter the type of account:\n");
		printf("1. Customer\n2. Agent\n3. Admin\n");
		printf("Your Response: ");
		scanf("%d", &type);
		printf("Enter your name: ");scanf("%s", name);
		strcpy(password,getpass("Enter the password: "));
		if(type == 3){
			int attempt = 1;
			while(1){
				strcpy(secret_pin, getpass("Enter secret PIN to create ADMIN account: "));attempt++;
				if(strcmp(secret_pin, "root")!=0 && attempt<=3) printf("Invalid PIN. Please try again.\n");
				else break;
			}
			if(!strcmp(secret_pin, "root"));
			else exit(0);
		}
		write(sock, &type, sizeof(type));
		write(sock, &name, sizeof(name));
		write(sock, &password, strlen(password));

		read(sock, &acc_no, sizeof(acc_no));
		printf("Remember the account no of further login: %d\n", acc_no);
		while(getchar()!='\n');
		getchar();		
		return 2;
	}
	else
		return 3;
}
