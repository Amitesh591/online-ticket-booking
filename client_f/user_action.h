int view_booking(int sock);

int do_user_action(int sock, int opt){
	switch(opt){
		case 1:{
			//book a ticket
			int trains, trainid, trainavseats, trainno, required_seats;
			char trainname[20];
			write(sock, &opt, sizeof(opt));
			read(sock, &trains, sizeof(trains));
			printf("ID\tT_NO\tAV_SEAT\tTRAIN NAME\n");
			while(trains--){
				read(sock, &trainid, sizeof(trainid));
				read(sock, &trainno, sizeof(trainno));
				read(sock, &trainavseats, sizeof(trainavseats));
				read(sock, &trainname, sizeof(trainname));
				if(strcmp(trainname, "deleted")!=0)
				printf("%d\t%d\t%d\t%s\n", trainid, trainno, trainavseats, trainname);
			}
			printf("Enter the train ID: "); scanf("%d", &trainid);
			write(sock, &trainid, sizeof(trainid));
			read(sock, &trainavseats, sizeof(trainavseats));
			printf("Enter the number of seats: "); scanf("%d", &required_seats);
			if(trainavseats>=required_seats && required_seats>0)
				write(sock, &required_seats, sizeof(required_seats));
			else{
				required_seats = -1;
				write(sock, &required_seats, sizeof(required_seats));
			}
			read(sock, &opt, sizeof(opt));
			
			if(opt == 1) printf("Tickets booked successfully\n");
			else printf("Tickets were not booked. Please try again.\n");
			printf("Press any key to continue...\n");
			while(getchar()!='\n');
			getchar();
			while(!getchar());
			return 1;
		}
		case 2:{
			//View your bookings
			write(sock, &opt, sizeof(opt));
			view_booking(sock);
			read(sock, &opt, sizeof(opt));
			return 2;
		}
		case 3:{
			//update bookings
			int val;
			write(sock, &opt, sizeof(opt));
			int ret_val = view_booking(sock);
			if(ret_val!=-2){

				printf("Enter the booking id to be updated: "); scanf("%d", &val);
				write(sock, &val, sizeof(int));	//Booking ID
				printf("What information do you want to update:\n1.Increase No of Seats\n2. Decrease No of Seats\nYour Choice: ");
				scanf("%d", &val);
				write(sock, &val, sizeof(int));	//Increase or Decrease
				if(val == 1){
					printf("How many tickets do you want to increase: ");scanf("%d",&val);
					write(sock, &val, sizeof(int));	//No of Seats
				}else if(val == 2){
					printf("How many tickets do you want to decrease: ");scanf("%d",&val);
					write(sock, &val, sizeof(int));	//No of Seats		
				}
				read(sock, &opt, sizeof(opt));
				if(opt == -2)
					printf("Operation failed. No more available seats\n");
				else printf("Operation succeded.\n");
			}
			while(getchar()!='\n');
			getchar();
			return 3;
		}
		case 4: {
			write(sock, &opt, sizeof(opt));
			int ret_val = view_booking(sock);
			if(ret_val!=-2){
				int val;
				printf("Enter the booking id to be deleted: "); scanf("%d", &val);
				write(sock, &val, sizeof(int));	//Booking ID
				read(sock, &opt, sizeof(opt));
				if(opt == -2)
				printf("Operation failed. No more available seats\n");
				else printf("Operation succeded.\n");
			}	
			while(getchar()!='\n');
			getchar();
			return 3;
			}
		case 5: {
			write(sock, &opt, sizeof(opt));
			read(sock, &opt, sizeof(opt));
			if(opt == 5) printf("Logged out successfully.\n");
			while(getchar()!='\n');
			getchar();
			return -1;
			break;
		}
		default: return -1;
	}
}


int view_booking(int sock){
	int entries;
	read(sock, &entries, sizeof(int));
	if(entries == 0) {
		printf("No records found.\n");
		return -2;
	}
	else printf("Your recent %d bookings are :\n", entries);
	while(!getchar());
	while(entries--){
		int bid, bks_seat, bke_seat, cancelled;
		char trainname[20];
		read(sock,&bid, sizeof(bid));
		read(sock,&trainname, sizeof(trainname));
		read(sock,&bks_seat, sizeof(int));
		read(sock,&bke_seat, sizeof(int));
		read(sock,&cancelled, sizeof(int));
		if(!cancelled)
		printf("BookingID: %d\tTicket Count: %d\tTRAIN :%s\n", bid, bke_seat-bks_seat+1, trainname);
	}
	printf("Press ENTER to continue...\n");
	while(getchar()!='\n');
	getchar();
	return 0;
}
