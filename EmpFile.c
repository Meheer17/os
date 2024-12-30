#include <stdio.h>
struct Employee
{
    int empId;
    char empName[50];
    float empSalary;
};
int main()
{
    FILE *filePtr = fopen("employee.dat", "rb+");
    if (!filePtr)
        filePtr = fopen("employee.dat", "wb+");
    if (!filePtr)
        return printf("Error creating the file.\n"), 1;
    struct Employee emp;
    int choice;
    while (1)
    {
        printf("\n1. Add 2. Display 3. Update 4. Exit: ");
        scanf("%d", &choice);
        if (choice == 4)
            break;
        printf("Enter ID: ");
        scanf("%d", &emp.empId);
        fseek(filePtr, (emp.empId - 1) * sizeof(emp), SEEK_SET);
        switch (choice)
        {
        case 1:
            printf("Enter Name: ");
            scanf("%s", emp.empName);
            printf("Enter Salary: ");
            scanf("%f", &emp.empSalary);
            fwrite(&emp, sizeof(emp), 1, filePtr);
            break;
        case 2:
            fread(&emp, sizeof(emp), 1, filePtr);
            printf("ID: %d\nName: %s\nSalary: %.2f\n",
                   emp.empId, emp.empName, emp.empSalary);
            break;
        case 3:
            fread(&emp, sizeof(emp), 1, filePtr);
            printf("Enter Name: ");
            scanf("%s", emp.empName);
            printf("Enter Salary: ");
            scanf("%f", &emp.empSalary);
            fseek(filePtr, (emp.empId - 1) * sizeof(emp), SEEK_SET);
            fwrite(&emp, sizeof(emp), 1, filePtr);
            break;
        }
    }
    fclose(filePtr);
    return 0;
}