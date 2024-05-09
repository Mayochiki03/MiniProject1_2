#include <stdio.h>
#include <math.h>
struct EnergyValue
{
    int choice[5];
    float input[10], ServiceCharge, Ft, EnergyCharge[10], keepvalue[10], keepReactive, sumkeepvalue, vat7, sum;
} point;

line(int l)
{
    int i;
    for (i = 0; i <= l; i++)
    {
        printf("-");
    }
}
head()
{
    printf("\t\t\t******** Electricity Tariff ********\n");
    line(89);
    printf("\n|  Type 1.1 Residentail Service (Normal Tariff / Progressive Rate) \t\tEnter 1  |\n");
    line(89);
    printf("\n|  Type 1.2 Residentail Service (TOU tariff) \t\t\t\t\tEnter 2  |\n");
    line(89);
    printf("\n|  Type 2.1 Small General Service (Normal Tariff / Progressive Rate) \t\tEnter 3  |\n");
    line(89);
    printf("\n|  Type 2.2 Small General Service (TOU tariff) \t\t\t\t\tEnter 4  |\n");
    line(89);
    printf("\n|  Type 3.1 Medium General Service (Normal Tariff) \t\t\t\tEnter 5  |\n");
    line(89);
    printf("\n|  Type 3.2 Medium General Service (TOU Tariff) \t\t\t\tEnter 6  |\n");
    line(89);
    printf("\n|  Type 4.1 Large General Service (TOD tariff) \t\t\t\t\tEnter 7  |\n");
    line(89);
    printf("\n|  Type 4.2 Large general service (TOU Tariff) \t\t\t\t\tEnter 8  |\n");
    line(89);
    printf("\n|  Type 5.1 Specific Business Service (TOU tariff) \t\t\t\tEnter 9  |\n");
    line(89);
    printf("\n|  Type 5.2 Specific Business Service (Normal Tariff) \t\t\t\tEnter 10 |\n");
    line(89);
    printf("\n|  Type 6.1 Government Institutions and non-profit organization (Normal Tariff) Enter 11 |\n");
    line(89);
    printf("\n|  Type 6.2 Government Institutions and non-profit organization (TOU Tariff) \tEnter 12 |\n");
    line(89);
    printf("\n|  Type 7.1 WATER PUMPING FOR AGRICULTURAL PURPOSES (Normal tariff) \t\tEnter 13 |\n");
    line(89);
    printf("\n|  Type 7.2 WATER PUMPING FOR AGRICULTURAL PURPOSES (TOU tariff) \t\tEnter 14 |\n");
    line(89);
    printf("\n|  Type 8 Temporary Tariff \t\t\t\t\t\t\tEnter 15 |\n");
    line(89);
}
inputenergy()
{
    printf("Customer Used Energy : ");
    scanf("%f", &point.input[2]);
}
inputonpeak()
{
    printf("Used Energy during On Peak Period : ");
    scanf("%f", &point.input[4]);
}
inputoffpeak()
{
    printf("Used Energy during Off Peak Period : ");
    scanf("%f", &point.input[5]);
}
inputdemand()
{
    printf("Used Demand during On Peak Period : ");
    scanf("%f", &point.input[6]);
}
inputpartial()
{
    printf("Used Demand during Partial Peak : ");
    scanf("%f", &point.input[7]);
}
inputReactivePower()
{
    printf("Used Reactive Power : ");
    scanf("%f", &point.input[8]);
}
main()
{
    int z;
    system("cls");
top:
    head();
    printf("\n\nEnter choice :");
    scanf("%d", &point.choice[1]);
    system("cls");
    switch (point.choice[1])
    {
    case 1: // Schedule 1 Residential (1.1 Normal Rate)
    drop1:
        printf("1.1.1 Consume up to 150 kWh. per Month \t\tEnter 1\n");
        line(54);
        printf("\n1.1.2 Consume over 150 kWh. per Month \t\tEnter 2\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 8.19;
            inputenergy();
            fn_Type1_1_1();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 24.62;
            inputenergy();
            fn_Type1_1_2();
            SUM();
        }
        else
            goto drop1;
        break;
    case 2: // Schedule 1 Residential (1.2 Time of Use Rate (TOU))
    drop2:
        printf("Voltage  22-33 kv \t\tEnter 1\n");
        line(40);
        printf("\nBelow 22kv \t\t\tEnter 2\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputonpeak();
            inputoffpeak();
            fn_Type1_2();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 24.62;
            inputonpeak();
            inputoffpeak();
            fn_Type1_2();
            SUM();
        }
        else
            goto drop2;
        break;
    case 3: // Schedule 2 Small General Service (2.1 Normal Rate)
    drop3:
        printf("Voltage  22-33 kv \t\tEnter 1\n");
        line(40);
        printf("\nBelow 22kv \t\t\tEnter 2\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputenergy();
            fn_Type2_1();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 33.29;
            inputenergy();
            fn_Type2_1();
            SUM();
        }
        else
            goto drop3;
        break;
    case 4: // Schedule 2 Small General Service (2.2 Time of Use Rate (TOU))
    drop4:
        printf("Voltage  22-33 kv \t\tEnter 1\n");
        line(40);
        printf("\nBelow 22kv \t\t\tEnter 2\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputonpeak();
            inputoffpeak();
            fn_Type2_2();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 33.29;
            inputonpeak();
            inputoffpeak();
            fn_Type2_2();
            SUM();
        }
        else
            goto drop4;
        break;
    case 5: // Schedule 3 Medium General Service (3.1 Normal Rate)
    drop5:
        printf("69 kv and over \t\t\tEnter 1\n");
        line(45);
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputenergy();
            inputReactivePower();
            fn_Type3_1();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputenergy();
            inputReactivePower();
            fn_Type3_1();
            SUM();
        }
        else if (point.choice[3] == 3)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputenergy();
            inputReactivePower();
            fn_Type3_1();
            SUM();
        }
        else
            goto drop5;

        break;
    case 6: // Schedule 3 Medium General Service (3.2 Time of Use Rate (TOU))
    drop6:
        printf("69 kv and over \t\t\tEnter 1\n");
        line(45);
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type3_2();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type3_2();
            SUM();
        }
        else if (point.choice[3] == 3)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type3_2();
            SUM();
        }
        else
            goto drop6;
        break;
    case 7: // Schedule 4 Large General Service (4.1 Time of Day Rate (TOD))
    drop7:
        printf("69 kv and over \t\t\tEnter 1\n");
        line(45);
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputpartial();
            inputenergy();
            inputReactivePower();
            fn_Type4_1();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputpartial();
            inputenergy();
            inputReactivePower();
            fn_Type4_1();
            SUM();
        }
        else if (point.choice[3] == 3)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputpartial();
            inputenergy();
            inputReactivePower();
            fn_Type4_1();
            SUM();
        }
        else
            goto drop7;
        break;
    case 8: // Schedule 4 Large General Service (4.2 Time of Use Rate (TOU))
    drop8:
        printf("69 kv and over \t\t\tEnter 1\n");
        line(45);
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type4_2();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type4_2();
            SUM();
        }
        else if (point.choice[3] == 3)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type4_2();
            SUM();
        }
        else
            goto drop8;
        break;
    case 9: // Schedule 5 Specific Business Service (5.1 Time of Use Rate (TOU))
    drop9:
        printf("69 kv and over \t\t\tEnter 1\n");
        line(45);
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type5_1();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type5_1();
            SUM();
        }
        else if (point.choice[3] == 3)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            inputReactivePower();
            fn_Type5_1();
            SUM();
        }
        else
            goto drop9;
        break;
    case 10: // Schedule 5 Specific Business Service (5.2 Whom does not installed with TOU meter)
    drop10:
        printf("69 kv and over \t\t\tEnter 1\n");
        line(45);
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputenergy();
            inputReactivePower();
            fn_Type5_2();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputenergy();
            inputReactivePower();
            fn_Type5_2();
            SUM();
        }
        else if (point.choice[3] == 3)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputenergy();
            inputReactivePower();
            fn_Type5_2();
            SUM();
        }
        else
            goto drop10;
        break;
    case 11: // Schedule 6 Non-Profit Organization (6.1 Normal Rate)
    drop11:
        printf("69 kv and over \t\t\tEnter 1\n");
        line(45);
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputenergy();
            fn_Type6_1();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 312.24;
            inputenergy();
            fn_Type6_1();
            SUM();
        }
        else if (point.choice[3] == 3)
        {
            point.ServiceCharge = 20.00;
            inputenergy();
            fn_Type6_1();
            SUM();
        }
        else
            goto drop11;
        break;
    case 12: // Schedule 6 Non-Profit Organization (6.2 Time of Use Rate (TOU))
    drop12:
        printf("69 kv and over \t\t\tEnter 1\n");
        line(45);
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");
        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            fn_Type5_1();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            fn_Type5_1();
            SUM();
        }
        else if (point.choice[3] == 3)
        {
            point.ServiceCharge = 312.24;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            fn_Type5_1();
            SUM();
        }
        else
            goto drop12;
        break;
    case 13: // Schedule 7 Agricultural Pumping (7.1 Normal Rate)
        system("cls");
        point.ServiceCharge = 115.16;
        inputenergy();
        fn_Type7_1();
        SUM();
        break;
    case 14: // Schedule 7 Agricultural Pumping (7.2 Time of Use Rate (TOU))
    drop14:
        printf("\nVoltage  22-33 kv \t\tEnter 2\n");
        line(45);
        printf("\nBelow 22kv \t\t\tEnter 3\n");
        printf("\nEnter choice :");
        scanf("%d", &point.choice[3]);
        system("cls");

        if (point.choice[3] == 1)
        {
            point.ServiceCharge = 204.07;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            fn_Type7_2();
            SUM();
        }
        else if (point.choice[3] == 2)
        {
            point.ServiceCharge = 204.07;
            inputdemand();
            inputonpeak();
            inputoffpeak();
            fn_Type7_2();
            SUM();
        }
        else
            goto drop14;
        break;
    case 15: // Schedule 8 Temporary Service  (8 Normal Rate)
        system("cls");
        inputenergy();
        fn_Type8();
        SUM();
        break;
    default:
        goto top;
        break;
    }
    char a;
    printf("Do you want do it again ? Enter y :");
    scanf(" %c", &a);
    if (a == 'y' || a == 'Y')
    {
        goto top;
    }else
    system("cls");

}
// Schedule 1 Residential
fn_Type1_1_1() //(1.1.1 Normal Rate)
{
    point.Ft = point.input[2] * 0.9343;
    float i;
    do
    {
        if (point.input[2] <= 15)
        {
            point.EnergyCharge[1] = 2.3488;
            point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
            point.input[2] = 0;
        }
        if (point.input[2] >= 16 && point.input[2] <= 25)
        {
            i = point.input[2] - 15;
            point.EnergyCharge[2] = 2.9882;
            point.keepvalue[2] = point.EnergyCharge[2] * i;
            point.input[2] = point.input[2] - i;
        }
        if (point.input[2] >= 26 && point.input[2] <= 35)
        {
            i = point.input[2] - 25;
            point.EnergyCharge[3] = 3.2405;
            point.keepvalue[3] = point.EnergyCharge[3] * i;
            point.input[2] = point.input[2] - i;
        }
        if (point.input[2] >= 36 && point.input[2] <= 100)
        {
            i = point.input[2] - 35;
            point.EnergyCharge[4] = 3.6237;
            point.keepvalue[4] = point.EnergyCharge[4] * i;
            point.input[2] = point.input[2] - i;
        }
        if (point.input[2] >= 101 && point.input[2] <= 150)
        {
            i = point.input[2] - 100;
            point.EnergyCharge[5] = 3.7171;
            point.keepvalue[5] = point.EnergyCharge[5] * i;
            point.input[2] = point.input[2] - i;
        }
        if (point.input[2] >= 151 && point.input[2] <= 400)
        {
            i = point.input[2] - 150;
            point.EnergyCharge[6] = 4.2218;
            point.keepvalue[6] = point.EnergyCharge[6] * i;
            point.input[2] = point.input[2] - i;
        }
        if (point.input[2] > 400)
        {
            i = point.input[2] - 400;
            point.EnergyCharge[7] = 4.4217;
            point.keepvalue[7] = point.EnergyCharge[7] * i;
            point.input[2] = point.input[2] - i;
        }
    } while (point.input[2] != 0);
}
fn_Type1_1_2() //(1.1.2 Normal Rate)
{
    point.Ft = point.input[2] * 0.9343;
    float i;
    do
    {
        if (point.input[2] <= 150)
        {
            point.EnergyCharge[1] = 3.2484;
            point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
            point.input[2] = 0;
        }
        if (point.input[2] >= 151 && point.input[2] <= 400)
        {
            i = point.input[2] - 150;
            point.EnergyCharge[2] = 4.2218;
            point.keepvalue[2] = point.EnergyCharge[2] * i;
            point.input[2] = point.input[2] - i;
        }
        if (point.input[2] > 400)
        {
            i = point.input[2] - 400;
            point.EnergyCharge[3] = 4.4217;
            point.keepvalue[3] = point.EnergyCharge[3] * i;
            point.input[2] = point.input[2] - i;
        }
    } while (point.input[2] != 0);
}
fn_Type1_2() //(1.2 Time of Use Rate (TOU))
{
    point.input[2] = point.input[4] + point.input[5];
    point.Ft = point.input[2] * 0.9343;
    float i;

    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[4] * 5.1135;
        point.keepvalue[2] = point.input[5] * 2.6037;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[4] * 5.7982;
        point.keepvalue[2] = point.input[5] * 2.6369;
    }
}
// Schedule 2 Small General Service
fn_Type2_1() //(2.1 Normal Rate)
{
    point.Ft = point.input[2] * 1.5492;
    float i;

    if (point.choice[3] == 1)
    {
        point.EnergyCharge[1] = 3.9086;
        point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
    }
    else if (point.choice[3] == 2)
    {
        do
        {
            if (point.input[2] <= 150)
            {
                point.EnergyCharge[1] = 3.2484;
                point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
                point.input[2] = 0;
            }
            if (point.input[2] >= 151 && point.input[2] <= 400)
            {
                i = point.input[2] - 150;
                point.EnergyCharge[2] = 4.2218;
                point.keepvalue[2] = point.EnergyCharge[2] * i;
                point.input[2] = point.input[2] - i;
            }
            if (point.input[2] > 400)
            {
                i = point.input[2] - 400;
                point.EnergyCharge[2] = 4.4217;
                point.keepvalue[2] = point.EnergyCharge[2] * i;
                point.input[2] = point.input[2] - i;
            }
        } while (point.input[2] != 0);
    }
}
fn_Type2_2() // 2.2 Time of Use Rate (TOU))
{
    point.input[2] = point.input[4] + point.input[5];
    point.Ft = point.input[2] * 1.5492;

    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[4] * 5.1135;
        point.keepvalue[2] = point.input[5] * 2.6037;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[4] * 5.7982;
        point.keepvalue[2] = point.input[5] * 2.6369;
    }
}
// Schedule 3 Medium General Service
fn_Type3_1() //(3.1 Normal Rate)
{
    point.Ft = point.input[2] * 1.5492;
    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[6] * 175.70;
        point.keepvalue[2] = point.input[2] * 3.1097;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[6] * 196.26;
        point.keepvalue[2] = point.input[2] * 3.1471;
    }
    else if (point.choice[3] == 3)
    {
        point.keepvalue[1] = point.input[6] * 221.50;
        point.keepvalue[2] = point.input[2] * 3.1751;
    }
    point.input[6] = point.input[6] * 61.97;
    point.input[6] = point.input[6] / 100;
    point.keepReactive = point.input[8] - point.input[6];
}
fn_Type3_2() //(3.2 Time of Use Rate (TOU))
{
    point.input[2] = point.input[4] + point.input[5];
    point.Ft = point.input[2] * 1.5492;
    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[6] * 74.14;
        point.keepvalue[2] = point.input[4] * 4.1025;
        point.keepvalue[3] = point.input[5] * 2.5849;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[6] * 132.93;
        point.keepvalue[2] = point.input[4] * 4.1839;
        point.keepvalue[3] = point.input[5] * 2.6037;
    }
    else if (point.choice[3] == 3)
    {
        point.keepvalue[1] = point.input[6] * 210;
        point.keepvalue[2] = point.input[4] * 4.3297;
        point.keepvalue[3] = point.input[5] * 2.6369;
    }
    point.input[6] = point.input[6] * 61.97;
    point.input[6] = point.input[6] / 100;
    point.keepReactive = point.input[8] - point.input[6];
}
// Schedule 4 Large General Service
fn_Type4_1() //(4.1 Time of Day Rate (TOD))
{
    point.Ft = point.input[2] * 1.5492;
    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[6] * 224.30;
        point.keepvalue[2] = point.input[2] * 3.1097;
        if (point.input[7] > point.input[6])
        {
            point.input[7] = point.input[7] - point.input[6];
            point.keepvalue[3] = point.input[7] * 29.91;
        }
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[6] * 285.05;
        point.keepvalue[2] = point.input[2] * 3.1471;
        if (point.input[7] > point.input[6])
        {
            point.input[7] = point.input[7] - point.input[6];
            point.keepvalue[3] = point.input[7] * 58.88;
        }
    }
    else if (point.choice[3] == 3)
    {
        point.keepvalue[1] = point.input[6] * 332.71;
        point.keepvalue[2] = point.input[2] * 3.1751;
        if (point.input[7] > point.input[6])
        {
            point.input[7] = point.input[7] - point.input[6];
            point.keepvalue[3] = point.input[7] * 68.22;
        }
    }
    point.input[6] = point.input[6] * 61.97;
    point.input[6] = point.input[6] / 100;
    point.keepReactive = point.input[8] - point.input[6];
}
fn_Type4_2() //(4.2 Time of Use Rate (TOU))
{
    point.input[2] = point.input[4] + point.input[5];
    point.Ft = point.input[2] * 1.5492;
    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[6] * 74.14;
        point.keepvalue[2] = point.input[4] * 4.1025;
        point.keepvalue[3] = point.input[5] * 2.5849;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[6] * 132.93;
        point.keepvalue[2] = point.input[4] * 4.1839;
        point.keepvalue[3] = point.input[5] * 2.6037;
    }
    else if (point.choice[3] == 3)
    {
        point.keepvalue[1] = point.input[6] * 210;
        point.keepvalue[2] = point.input[4] * 4.3297;
        point.keepvalue[3] = point.input[5] * 2.6369;
    }
    point.input[6] = point.input[6] * 61.97;
    point.input[6] = point.input[6] / 100;
    point.keepReactive = point.input[8] - point.input[6];
}
// Schedule 5 Specific Business Service
fn_Type5_1() //(5.1 Time of Use Rate (TOU))
{
    point.input[2] = point.input[4] + point.input[5];
    point.Ft = point.input[2] * 1.5492;
    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[6] * 74.14;
        point.keepvalue[2] = point.input[4] * 4.1025;
        point.keepvalue[3] = point.input[5] * 2.5849;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[6] * 132.93;
        point.keepvalue[2] = point.input[4] * 4.1839;
        point.keepvalue[3] = point.input[5] * 2.6037;
    }
    else if (point.choice[3] == 3)
    {
        point.keepvalue[1] = point.input[6] * 210.00;
        point.keepvalue[2] = point.input[4] * 4.3297;
        point.keepvalue[3] = point.input[5] * 2.6369;
    }
    point.input[6] = point.input[6] * 61.97;
    point.input[6] = point.input[6] / 100;
    point.keepReactive = point.input[8] - point.input[6];
}
fn_Type5_2() //(5.2 Whom does not installed with TOU meter)
{
    point.Ft = point.input[2] * 1.5492;
    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[6] * 220.56;
        point.keepvalue[2] = point.input[2] * 3.1097;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[6] * 256.07;
        point.keepvalue[2] = point.input[2] * 3.1471;
    }
    else if (point.choice[3] == 3)
    {
        point.keepvalue[1] = point.input[6] * 276.64;
        point.keepvalue[2] = point.input[2] * 3.1751;
    }
    point.input[6] = point.input[6] * 61.97;
    point.input[6] = point.input[6] / 100;
    point.keepReactive = point.input[8] - point.input[6];
}
// Schedule 6 Non-Profit Organization
fn_Type6_1() //(6.1 Normal Rate)
{
    point.Ft = point.input[2] * 1.5492;
    float i;

    if (point.choice[3] == 1)
    {
        point.EnergyCharge[1] = 3.4149;
        point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
    }
    else if (point.choice[3] == 2)
    {
        point.EnergyCharge[1] = 3.5849;
        point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
    }
    else if (point.choice[3] == 3)
    {
        do
        {
            if (point.input[2] <= 10)
            {
                point.EnergyCharge[1] = 2.8013;
                point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
                point.input[2] = 0;
            }
            if (point.input[2] > 10)
            {
                i = point.input[2] - 10;
                point.EnergyCharge[2] = 2.8919;
                point.keepvalue[2] = point.EnergyCharge[2] * i;
                point.input[2] = point.input[2] - i;
            }
        } while (point.input[2] != 0);
    }
}
fn_Type6_2() //(6.2 Time of Use Rate (TOU))
{
    point.input[2] = point.input[4] + point.input[5];
    point.Ft = point.input[2] * 1.5492;
    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[6] * 74.14;
        point.keepvalue[2] = point.input[4] * 4.1025;
        point.keepvalue[3] = point.input[5] * 2.5849;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[6] * 132.93;
        point.keepvalue[2] = point.input[4] * 4.1839;
        point.keepvalue[3] = point.input[5] * 2.6037;
    }
    else if (point.choice[3] == 3)
    {
        point.keepvalue[1] = point.input[6] * 210.00;
        point.keepvalue[2] = point.input[4] * 4.3297;
        point.keepvalue[3] = point.input[5] * 2.6369;
    }
}
// Schedule 7 Agricultural Pumping
fn_Type7_1() //(7.1 Normal Rate)
{
    point.Ft = point.input[2] * 1.5492;
    float i;
    do
    {
        if (point.input[2] <= 100)
        {
            point.EnergyCharge[1] = 2.0889;
            point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
            point.input[2] = 0;
        }
        if (point.input[2] > 101)
        {
            i = point.input[2] - 100;
            point.EnergyCharge[2] = 3.2405;
            point.keepvalue[2] = point.EnergyCharge[2] * i;
            point.input[2] = point.input[2] - i;
        }
        
    } while (point.input[2] != 0);
}
fn_Type7_2() // 7.2 Time of Use Rate (TOU))
{
    point.input[2] = point.input[4] + point.input[5];
    point.Ft = point.input[2] * 1.5492;
    if (point.choice[3] == 1)
    {
        point.keepvalue[1] = point.input[6] * 132.92;
        point.keepvalue[2] = point.input[4] * 4.1839;
        point.keepvalue[3] = point.input[5] * 2.6037;
    }
    else if (point.choice[3] == 2)
    {
        point.keepvalue[1] = point.input[6] * 210.00;
        point.keepvalue[2] = point.input[4] * 4.3297;
        point.keepvalue[3] = point.input[5] * 2.6369;
    }
}
// Schedule 8 Temporary Service
fn_Type8() //(8 Normal Rate)
{
    point.Ft = point.input[2] * 1.5492;
    point.EnergyCharge[1] = 6.8025;
    point.keepvalue[1] = point.EnergyCharge[1] * point.input[2];
}
SUM()
{
    float rounded_number = round(point.keepReactive);
    rounded_number = rounded_number * 56.07;
    point.sumkeepvalue = point.keepvalue[1] + point.keepvalue[2] + point.keepvalue[3] + point.keepvalue[4] + point.keepvalue[5] + point.keepvalue[6] + point.keepvalue[7];
    // printf("%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n", point.keepvalue[1], point.keepvalue[2], point.keepvalue[3], point.keepvalue[4], point.keepvalue[5], point.keepvalue[6], point.keepvalue[7]);
    // system("cls");

    // Section 1 Base Tariff
    printf("\n\nSection 1 Base Tariff");
    printf("\n\tEnergy Charge  = %.2f\n", point.sumkeepvalue);
    printf("\tServiceCharge  = %.2f\n", point.ServiceCharge);
    point.sumkeepvalue = point.sumkeepvalue + point.ServiceCharge;
    if (rounded_number >= 1)
    {
        point.sumkeepvalue = point.sumkeepvalue + rounded_number;
        printf("Reactive = : %.2f\n", rounded_number);
    }
    else if (rounded_number <= 0)
    {
        rounded_number = 0;
    }
    printf("\n\tTotal Base Tariff  = %.2f\n", point.sumkeepvalue);

    // Section 2 (Ft) Change
    printf("\nSection 2 (Ft) Change");
    point.sumkeepvalue = point.sumkeepvalue + point.Ft;
    printf("\nUsed Energy X Ft Rate = %.2f \n", point.Ft);

    // Section 3 Tax 7 Percent
    printf("\nSection 3 Tax 7 Percent");
    point.vat7 = point.sumkeepvalue * 7;
    point.vat7 = point.vat7 / 100;
    point.sum = point.sumkeepvalue + point.vat7;
    printf("vat = %.2f \n", point.vat7);

    // Total
    printf("Total Electricity Charge = %.2f \n\n\n", point.sum);
}
