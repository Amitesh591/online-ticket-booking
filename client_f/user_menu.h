
#include "admin_action.h"
#include "user_action.h"

int user_menu(int sock, int type){
	int opt = 0;
	if(type == 1 || type == 2){
		system("clear");
		printf("-------OPTIONS -------\n");
		printf("1. Book Ticket\n");
		printf("2. View Bookings\n");
		printf("3. Update Booking\n");
		printf("4. Cancel booking\n");
		printf("5. Logout\n");
		printf("Your Choice: ");
		scanf("%d", &opt);
		return do_user_action(sock, opt);
		return -1;
	}
	else{
		system("clear");
		printf("------- OPTIONS -------\n");
		printf("1. Add Train\n");
		printf("2. Delete Train\n");
		printf("3. Modify Train\n");
		printf("4. Add Root User\n");
		printf("5. Delete User\n");
		printf("6. Logout\n");
		printf("Your Choice: ");
		scanf("%d", &opt);
		return do_admin_action(sock, opt);
	}
}
