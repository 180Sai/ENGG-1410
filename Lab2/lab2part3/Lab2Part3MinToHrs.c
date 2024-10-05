#include <stdio.h>

int main() {
    int total_minutes, hours, minutes, rounded_minutes;
    // Prompt user for input
    printf("Enter total minutes: ");

    //scanf goes here
    scanf("%d", &total_minutes);

    //Your logic to convert total minutes to hours and remaining minutes goes below this line.
    hours = total_minutes/60;
    minutes = total_minutes % 60;

    // Round remaining minutes to the nearest quarter hour
    // your logic to round the minutes goes below this line.
    if(minutes >= 0 && minutes <= 7)
        rounded_minutes = 0;
    else if (minutes >= 8 && minutes <= 22)
        rounded_minutes = 15;
    else if (minutes >= 23 && minutes <= 37)
        rounded_minutes = 30;
    else if (minutes >= 38 && minutes <= 52)
        rounded_minutes = 45;
    else
    {
        rounded_minutes = 0;
        hours++;
    }
    
    

    // Output the result
    printf("That is equivalent to:\n");
    printf("%d hours and %d minutes (rounded to nearest quarter hour)\n", hours, rounded_minutes);

    return 0;
}
