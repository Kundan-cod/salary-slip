#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int e_id;
    char ename[50];
    char designation[50];
    char dateOfJoining[11];
    char payPeriod[10];
    int salary;
    float pf;
    float hra;
    float ta;
    float gs;
};

struct PaySlip {
    char employeeName[50];
    char designation[50];
    int employeeID;
    char dateOfJoining[11]; // Format: DD/MM/YYYY
    char payPeriod[10];     // Month and Year
    float basicSalary;
    float houseRentAllowance;
    float conveyanceAllowance;
    float childrenEducationAllowance;
    float fixedAllowance;
    float grossEarnings;
    float epfContribution;
    float professionalTax;
    float totalDeductions;
    float netPay;
};

void displayPaySlip(struct PaySlip payslip) {
    printf("\n=====================================\n");
    printf("             EMPLOYEE SUMMARY        \n");
    printf("=====================================\n");
    printf("Employee Name      : %s\n", payslip.employeeName);
    printf("Designation        : %s\n", payslip.designation);
    printf("Employee ID        : %d\n", payslip.employeeID);
    printf("Date of Joining    : %s\n", payslip.dateOfJoining);
    printf("Pay Period         : %s\n", payslip.payPeriod);

    printf("\n----------- EARNINGS ---------------\n");
    printf("Basic Salary                 : %.2f\n", payslip.basicSalary);
    printf("House Rent Allowance        : %.2f\n", payslip.houseRentAllowance);
    printf("Conveyance Allowance        : %.2f\n", payslip.conveyanceAllowance);
    printf("Children Education Allowance: %.2f\n", payslip.childrenEducationAllowance);
    printf("Fixed Allowance             : %.2f\n", payslip.fixedAllowance);
    printf("Gross Earnings              : %.2f\n", payslip.grossEarnings);

    printf("\n----------- DEDUCTIONS -------------\n");
    printf("EPF Contribution             : %.2f\n", payslip.epfContribution);
    printf("Professional Tax             : %.2f\n", payslip.professionalTax);
    printf("Total Deductions             : %.2f\n", payslip.totalDeductions);

    printf("\n---------- NET PAYABLE -------------\n");
    printf("Total Net Payable            : %.2f\n", payslip.netPay);
    printf("=====================================\n");
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employee_count = 0;

    char login_id[20], login_password[20];
    printf("=== Employee Login ===\n");
    printf("Enter Employee ID: ");
    scanf(" %19s", login_id);
    printf("Enter Password: ");
    scanf(" %19s", login_password);
    printf("\nLogin successful! Welcome, Employee %s\n", login_id);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enter Employee Information\n");
        printf("2. Display Salary Slips of All Employees\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (employee_count >= MAX_EMPLOYEES) {
                    printf("Maximum employee limit reached.\n");
                    break;
                }

                printf("\n--- Enter Employee Details ---\n");
                printf("Enter Employee ID: ");
                scanf("%d", &employees[employee_count].e_id);

                printf("Enter Employee Name: ");
                scanf(" %49[^\n]", employees[employee_count].ename);

                printf("Enter Designation: ");
                scanf(" %49[^\n]", employees[employee_count].designation);

                printf("Enter Date of Joining (DD/MM/YYYY): ");
                scanf(" %10s", employees[employee_count].dateOfJoining);

                printf("Enter Pay Period (e.g., March 2024): ");
                scanf(" %9[^\n]", employees[employee_count].payPeriod);

                printf("Enter Basic Salary: ");
                scanf("%d", &employees[employee_count].salary);

                employees[employee_count].pf = employees[employee_count].salary * 0.06f;
                employees[employee_count].hra = employees[employee_count].salary * 0.05f;
                employees[employee_count].ta = employees[employee_count].salary * 0.04f;
                employees[employee_count].gs = employees[employee_count].salary
                    + employees[employee_count].hra + employees[employee_count].ta;

                employee_count++;
                printf("Employee information saved successfully.\n");
                break;

            case 2:
                if (employee_count == 0) {
                    printf("No employee data entered yet.\n");
                    break;
                }

                printf("\n--- Displaying Salary Slips ---\n");
                for (int i = 0; i < employee_count; ++i) {
                    float educationAllowance = 500.0f;
                    float fixedAllowance = 1000.0f;
                    float professionalTax = 200.0f;

                    float gross = employees[i].gs + educationAllowance + fixedAllowance;
                    float deductions = employees[i].pf + professionalTax;
                    float net = gross - deductions;

                    struct PaySlip myPaySlip;

                    strcpy(myPaySlip.employeeName, employees[i].ename);
                    strcpy(myPaySlip.designation, employees[i].designation);
                    myPaySlip.employeeID = employees[i].e_id;
                    strcpy(myPaySlip.dateOfJoining, employees[i].dateOfJoining);
                    strcpy(myPaySlip.payPeriod, employees[i].payPeriod);

                    myPaySlip.basicSalary = (float)employees[i].salary;
                    myPaySlip.houseRentAllowance = employees[i].hra;
                    myPaySlip.conveyanceAllowance = employees[i].ta;
                    myPaySlip.childrenEducationAllowance = educationAllowance;
                    myPaySlip.fixedAllowance = fixedAllowance;
                    myPaySlip.grossEarnings = gross;
                    myPaySlip.epfContribution = employees[i].pf;
                    myPaySlip.professionalTax = professionalTax;
                    myPaySlip.totalDeductions = deductions;
                    myPaySlip.netPay = net;

                    displayPaySlip(myPaySlip);
                }
                break;

            case 3:
                printf("Exiting... Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
