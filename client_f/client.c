
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "account_login.h"
#include "user_menu.h"

#define PORT 8100

int Homepage(int sock_fd);
int user_menu(int sock_fd, int type);
int do_admin_action(int sock_fd, int action);
int do_action(int sock_fd, int choice);
int view_booking(int sock_fd);

int main(int argc, char * argv[]){
	char *server_ip;
	if(argc==2){
		server_ip = argv[1];
	}
	else
	{
	server_ip ="127.0.0.1";
	}
	int cli_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(cli_fd == -1){
		printf("Failed to create socket\n");
		exit(0);
	}
	struct sockaddr_in client_addr;
	client_addr.sin_family=AF_INET;
	client_addr.sin_port= htons(PORT);
	client_addr.sin_addr.s_addr = inet_addr(server_ip);
	if(connect(cli_fd, (struct sockaddr *)&client_addr, sizeof(client_addr))==-1){
		printf("Unable to connect to server\n");
		exit(0);
	}
	printf("Connection succesfully Established\n");

	while(Homepage(cli_fd)!=3);
	close(cli_fd);

	return 0;
}

int Homepage(int sock_fd){
	int ch;
	//-------------HOMEPAGE SCREEN--------------------//;

	system("clear");
	printf("--------Ticket_Booking HomePage--------\n");
	printf("1. Login \n");
	printf("2. Sign Up\n");
	printf("3. Quit\n");
	printf("--------Enter Your Choice--------\n");
	scanf("%d", &ch);
	write(sock_fd, &ch, sizeof(ch));
	int ret_val = account_login(ch,sock_fd);
	return ret_val;
	//home menu completed
	//user_menu
	//admin_action | user_action
}
