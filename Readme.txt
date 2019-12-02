

Name: 		Amitesh Anand
Roll No.: 	MT2019117
College:	IIIT Bangalore
Project Title:	Railway ticket booking system
Concept Used:   Socket programming and locking mechanism(file locking)



Functionality provided by the system:
1: Admin
	1.1: Managing Train details 
		1.1.1 Add
		1.1.2 Update
		1.1.3 Delete
	1.2: Managing Users in the system
		1.2.1 Delete Agent, Customer

2: Agent
	2.1: Can login from multiple systems.
	2.2: View tickets Booked.
	2.3: Book tickets.
	2.4: Manage tickets (update , cancel)

3: Customer
	3.1: Can login only from single system.
	3.2: Book tickets
	3.3: Manage tickets (update,cancel)
	3.4: View, Update bookings


Steps to run the Ticket_Booking System:

Run create_database.sh to create essential database files:
$ sh create_database.sh 

Run compiler.sh to create object file of server and client:
$ sh compiler.sh

***We are running our server application and client applicaion on port: 8100***

Run the server:
$ ./server

Run the client:
$ ./client [IP_Address of server]
Default value of IP: "127.0.0.1"


***First create a account of Admin by signup option using secret key "root".***
