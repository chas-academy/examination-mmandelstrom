//Write your code in this file
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13;
    float avg, total_avg = 0;
    char student_names[5][50];
    float student_averages[5] = {0};
    float highest_avg = 0;
    char highest_score_name[50];

    // Take userinput name and test scores
    for(int i = 0; i < 5; i++){
        printf("Input name and scores for student number %d: ", i + 1);
        int inputs = scanf("%s %d %d %d %d %d %d %d %d %d %d %d %d %d",
            student_names[i],
            &p1, &p2, &p3, &p4, &p5, &p6,
            &p7, &p8, &p9, &p10, &p11, &p12, &p13
        );

        // Validate input
        if(inputs != 14){
            printf("Incorrect input, please enter a name followed by 13 integers\n");
            while(getchar() != '\n'); // Clear buffer
            i--; // try again with same student
            continue;
        }

        // Validate input scores are between 0 and 10
        if(p1 < 0 || p1 > 10 ||
            p2 < 0 || p2 > 10 ||
            p3 < 0 || p3 > 10 ||
            p4 < 0 || p4 > 10 ||
            p5 < 0 || p5 > 10 ||
            p6 < 0 || p6 > 10 ||
            p7 < 0 || p7 > 10 ||
            p8 < 0 || p8 > 10 ||
            p9 < 0 || p9 > 10 ||
            p10 < 0 || p10 > 10 ||
            p11 < 0 || p11 > 10 ||
            p12 < 0 || p12 > 10 ||
            p13 < 0 || p13 > 10){
                printf("Invalid scores – all values must be between 0 and 10\n");
                while(getchar() != '\n');
                i--;
                continue;
        }

        // Calculate averages
        avg = (p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9 + p10 + p11 + p12 + p13) / 13.0;
        student_averages[i] = avg;
        total_avg += student_averages[i];
        student_names[i][0] = toupper(student_names[i][0]); //Capitalize fist letter of each name

        // Find and save studen with higest average score
        if(student_averages[i] > highest_avg){
            highest_avg = student_averages[i];
            strcpy(highest_score_name, student_names[i]);
        }

    }

    // Calculate total average, print highest score name
    total_avg /= 5;
    printf("%s\n", highest_score_name);

    // Check which students fall below total average and print their names
    for(int i = 0; i < 5; i++){
        if(student_averages[i] < total_avg){
            printf("%s\n", student_names[i]);
        }
    }

    return 0;
}