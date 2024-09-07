#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name_branch[20];   // الفرع
    char ID_manager[20];  // المدير
    double sales[12];// مبيعات الـ 12 شهر
} BRANCH; // عرفته  باسم Branch

void DataSales (BRANCH branches[],int n ){
    for (int i =0 ; i<n ; ++i)
    {

        printf("Enter data for branch %d:\n", i + 1);
        printf("\nEnter the name of branch: ");
        scanf("%s", branches[i].name_branch);//ادخال اسم الفرع
        printf("\nEnter the ID of Manager: ");
        scanf("%s", branches[i].ID_manager);//ادخال رقم للمدير
        for (int j = 0; j < 12; ++j)
        {
            printf("\nSales for month %d: \n", j + 1);
            scanf("%lf", &branches[i].sales[j]);//ادخال المبيعات لكل الشهور
        }

    }
}//f لبينات المبيعات

void Fun_Menu (){
    printf("\nMenu:\n\n");
    printf("\n 1. Calculate total sales of the company\n________________________________________\n");//احسب مجموع المبيعات
    printf("\n 2. Calculate the percentage share of each branch in the total sales\n___________________________________________________________________\n");
    //احسب النسبة المئوية للمبيعات
    printf("\n 3. Determine the month of peak sales\n_____________________________________\n");//نحدد الشهر الاكثر مبيعات
    printf("\n 4. Sort branches by sales for a specified month\n________________________________________________\n");//ترتيب الفروع حسب مبيعات الشهور
    printf("\n 5. Sort months by sales for a specified branch\n_______________________________________________\n");//ترتيب الشهور حسب مبيعات الفروع
    printf("\n\n Enter your choice: ");//اطلبها الاختيار
}//f القائمه للمستخدم

int Fun_Choice(){
    int choice;

    scanf("%d", &choice);//ادخال الاختيار


    return choice;
}//f الاختيارات للمستخدم

double Total_Sales (BRANCH branches[],int n);//f لجمالي المبيعات

void Prc_Sales(BRANCH branches[],int n,double totalSales);//f نسبه مئويه لكل فرع

int Max_SalesMonth(BRANCH branches[],int n );//f شهر الاعلي مبيعات

void Sort_BranchesBy_MONTHSales(BRANCH branches[],int n, int month); //f ترتيب الفروع حسب مبيعات الشهور

void Sort_MONTHSBy_BranchSales(BRANCH branches[],int branch_Index );//f ترتيب الشهور حسب مبيعات الفروع





int main()
{
    BRANCH branches[100]; //arr  لتخزين البيانات لكل فرع
    int num_branches=0; //عدد الفروع
    printf("Enter  the number of branches:  ");
    scanf("%d",&num_branches);

    //call_f  لحساب بيانات المبيعات للفروع
    DataSales(branches,num_branches);


    int choice, month, branch_Index;
    double totalSales ;

    do     //call_f القايمه و الخيارات للمسخدم
    {

        Fun_Menu();
        choice= Fun_Choice ();


        if (choice==1)     //call_f لجمالي المبيعات
        {

            totalSales =Total_Sales(branches,num_branches);
            printf("\nTotal sales of the company: %.2f\n\n", totalSales);

        }
        else if (choice == 2)  //call_f نسبه مئويه لكل فرع
        {

            totalSales =Total_Sales(branches,num_branches);

            Prc_Sales(branches,num_branches,totalSales);

        }
        else if (choice == 3)  //call_f شهر الاعلي مبيعات
        {
            month= Max_SalesMonth(branches,num_branches);
            printf("\nThe month of peak sales is: %d\n\n", month + 1);

        }
        else if (choice == 4)  //call_f ترتيب الفروع حسب مبيعات الشهور
        {
            printf("\nEnter the month from 1 to 12: \n");
            scanf("%d", &month);
            Sort_BranchesBy_MONTHSales(branches,num_branches,month -1);

        }
        else if (choice == 5) //call_f ترتيب الشهور حسب مبيعات الفروع
        {
            printf("\nEnter the branch index (1-%d): \n", num_branches );
            scanf("%d", &branch_Index+1);
            Sort_MONTHSBy_BranchSales(  branches, branch_Index );

        }
        else     // اختيار غلط
        {

            printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (1 for Yes, 0 for No): ");//هل يستمر ؟
        scanf("%d", &choice);
    }while (choice == 1) ;

    return 0;
}


double Total_Sales (BRANCH branches[],int n)//لجمالي المبيعات
{
    double total = 0;
    for (int i = 0; i < n; ++i)//للفروع
    {
        for (int j = 0; j < 12; ++j)//للشهور
        {
            total += branches[i].sales[j];//جمع المبيعات
        }
    }
    return total;
}
void Prc_Sales(BRANCH branches[],int n,double totalSales)//نسبه مئويه لكل فرع
{
    for (int i = 0; i < n; ++i)
    {
        double branchTotal = 0;
        for (int j = 0; j < 12; ++j)
        {
            branchTotal += branches[i].sales[j];
        }
        printf("Branch %s: %.2f%%\n", branches[i].name_branch, (branchTotal / totalSales) * 100);//حساب النسبه المئوية
    }
}

int Max_SalesMonth(BRANCH branches[],int n )// شهر الاعلي مبيعات
{
    double monthlySales[12] = {0};
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            monthlySales[j] += branches[i].sales[j];//المبيعات الشهريه
        }
    }

    int peakMonth = 0;
    for (int i = 1; i < 12; ++i)
    {
        if (monthlySales[i] > monthlySales[peakMonth])//تحديد اعلي شهر
        {
            peakMonth = i;
        }
    }
    return peakMonth;
}
void Sort_BranchesBy_MONTHSales(BRANCH branches[],int n, int month) //ترتيب الفروع حسب مبيعات الشهور
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (branches[j].sales[month] < branches[j + 1].sales[month])//
            {
                BRANCH temp = branches[j];// تبديل مؤقت لترتيب
                branches[j] = branches[j + 1];
                branches[j + 1] = temp;
            }
        }
    }

    // ترتيب الفروع
    printf("\nBranches sorted by sales in month %d:\n\n", month + 1);
    for (int i = 0; i < n; ++i)
    {
        printf("\n%d: Branch ID %s - Sales %.2f\n\n", i, branches[i].name_branch, branches[i].sales[month]);
    }
}
void Sort_MONTHSBy_BranchSales(BRANCH branches[],int branch_Index )// ترتيب الشهور حسب مبيعات الفروع
{
    double monthSales[12];
    for (int i = 0; i < 12; ++i)
    {
        monthSales[i] = branches[branch_Index].sales[i];
    }

    for (int i = 0; i < 12 - 1; ++i)
    {
        for (int j = 0; j <12 - i - 1; ++j)
        {
            if (monthSales[j] < monthSales[j + 1])
            {

                double temp = monthSales[j];
                monthSales[j] = monthSales[j + 1];
                monthSales[j + 1] = temp;
            }
        }
    }

    // نرتب الشهور
    printf("\nMonths sorted by sales for branch %s:\n\n", branches[branch_Index].name_branch);
    for (int i = 0; i < 12; ++i)
    {
        printf("\n%d: Month %d - Sales %.2f\n\n", i+1, i + 1, monthSales[i]);
    }
}
