#include <stdio.h>
#include <string.h>

int main() {
    char day[10];
    printf("Podaj dzień tygodnia (poniedziałek, wtorek, środa, czwartek, piątek, sobota, niedziela): ");
    scanf("%s", day);

    int start_day = 0; // 0 - poniedziałek, 1 - wtorek, ..., 6 - niedziela
    if (strcmp(day, "poniedziałek") == 0) start_day = 0;
    else if (strcmp(day, "wtorek") == 0) start_day = 1;
    else if (strcmp(day, "środa") == 0) start_day = 2;
    else if (strcmp(day, "czwartek") == 0) start_day = 3;
    else if (strcmp(day, "piątek") == 0) start_day = 4;
    else if (strcmp(day, "sobota") == 0) start_day = 5;
    else if (strcmp(day, "niedziela") == 0) start_day = 6;
    else {
        printf("Błąd: niepoprawny dzień tygodnia.\n");
        return 1;
    }

    printf("W roku 2025 %s przypada na następujące daty:\n", day);
    
    int day_of_week = 3; // 1 stycznia 2025 to środa
    for (int day_number = 1; day_number <= 365; day_number++) {
        if (day_of_week == start_day) {
            int month = 1, day_in_month = day_number;
            while (day_in_month > 0) {
                int days_in_month;
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
                    days_in_month = 31;
                } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                    days_in_month = 30;
                } else {
                    days_in_month = 28; // 2025 nie jest rokiem przestępnym
                }
                if (day_in_month <= days_in_month) {
                    printf("\t%d %s\n", day_in_month, (month == 1 ? "stycznia" : month == 2 ? "lutego" : month == 3 ? "marca" : month == 4 ? "kwietnia" : month == 5 ? "maja" : month == 6 ? "czerwca" : month == 7 ? "lipca" : month == 8 ? "sierpnia" : month == 9 ? "września" : month == 10 ? "października" : month == 11 ? "listopada" : "grudnia"));
                    break;
                }
                day_in_month -= days_in_month;
                month++;
            }
        }
        day_of_week = (day_of_week + 1) % 7; // przejście do następnego dnia tygodnia
    }

    return 0;
}