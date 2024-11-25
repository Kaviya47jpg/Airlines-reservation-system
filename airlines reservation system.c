#include <stdio.h>
#include <string.h>

#define MAX_SEATS 100
#define MAX_NAME_LEN 50

typedef struct {
    int seatNumber;
    char passengerName[MAX_NAME_LEN];
} Reservation;

Reservation reservations[MAX_SEATS];
int bookedSeats = 0;

// Function to check if a seat is already booked
int isSeatBooked(int seatNumber) {
    for (int i = 0; i < bookedSeats; i++) {
        if (reservations[i].seatNumber == seatNumber) {
            return 1;
        }
    }
    return 0;
}
// Function to book a ticket
void bookTicket() {
    if (bookedSeats >= MAX_SEATS) {
        printf("All seats are booked. No more seats available.\n");
        return;
    }

    int seatNumber;
    char passengerName[MAX_NAME_LEN];

    printf("Enter seat number (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > MAX_SEATS) {
        printf("Invalid seat number. Please enter a number between 1 and %d.\n", MAX_SEATS);
        return;
    }
    printf("Enter passenger name: ");
    bookedSeats++;

    printf("Ticket booked successfully! Seat number %d is reserved for %s.\n", seatNumber, passengerName);
}

// Function to display all booked tickets
void displayReservations() {
    if (bookedSeats == 0) {
        printf("No reservations found.\n");
        return;
    }

    printf("Current reservations:\n");
    for (int i = 0; i < bookedSeats; i++) {
        printf("Seat number %d: %s\n", reservations[i].seatNumber, reservations[i].passengerName);
    }
}
// Main function
int main() {
    int choice;

    while (1) {
        printf("\nAirline Reservation System\n");
        printf("1. Book a ticket\n");
        printf("2. Display reservations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                displayReservations();
                break;
            case 3:
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}