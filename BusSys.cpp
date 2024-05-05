//          <<<<<< Project >>>>>>
//     >>> Any Bus Ticketing System <<<
//                                       >> Information about >> 
//                                                                >> Employees
//                                                                >> Busses and their Specification
//                                                                >> Routes


#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

using namespace std;



class Employee 
{

    private:
    string emp_regno;
    string emp_fname;
    string emp_lname;
    string emp_age;
    string emp_cnic;
    string emp_phone;
    string emp_address;
    int emp_salary;
    string emp_rankd;

    public:
    void emp_add();
    void emp_showall();
    void emp_search();
    void emp_update();
    void emp_delete();
    void emp_allinfo();

};



class Routes
{

    public:
    string r_1 = "Peshawar--Nowshera--Attock--Taxila--Islamabad";
    string r_2 = "Islamabad--Gujarkhan--Jehlum--Gujrat--Gujranwala--Lahore";
    string r_3 = "Lahore--Faisalabad--Jhang--Khanewal--Multan";
    string r_4 = "Multan--Bhawalpur--Rahimyarkhan--Sukkur--Nawabshah--Hyderabad";
    string r_5 = "Hyderabad--Kotri--Nooriabad--Karachi";

    void route_show();
    void route_show_menu();

};



class Bus
{

    private:
    string bus_regno;
    string bus_brand;
    string bus_model;
    string bus_color;
    string bus_g_weight;
    string bus_manu_date;
    int bus_cost;
    int bus_pes_cap;
    string bus_eng;
    string bus_eng_power;
    string bus_f_type;
    int bus_f_cap;
    float bus_mileage;

    public:
    void bus_add();
    void bus_showall();
    void bus_search();
    void bus_update();
    void bus_delete();
    void bus_allinfo();

};



class Ride : public Bus, public Employee, public Routes
{

    private:
    string bus_regno;
    string bus_brand;
    string bus_model;
    string bus_color;
    string bus_g_weight;
    string bus_manu_date;
    int bus_cost;
    int bus_pes_cap;
    string bus_eng;
    string bus_eng_power;
    string bus_f_type;
    int bus_f_cap;
    float bus_mileage;

    string emp_regno;
    string emp_fname;
    string emp_lname;
    string emp_age;
    string emp_cnic;
    string emp_phone;
    string emp_address;
    int emp_salary;
    string emp_rankd;

    string rid_regno;
    string rid_route;


    public:
    void ride_add();
    void ride_showall();
    void ride_delete();

};



class IMTravels : public Ride
{
    public:
    void mainmenu();
};



void Routes::route_show()
{

    cout << "\n*********************************************************************************";
    cout << "\nRoute 1 ===>  " << r_1
         << "\nRoute 2 ===>  " << r_2
         << "\nRoute 3 ===>  " << r_3
         << "\nRoute 4 ===>  " << r_4
         << "\nRoute 5 ===>  " << r_5;
    cout << "\n*********************************************************************************\n";

}



void Routes::route_show_menu()
{

    system("cls");
    
    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";


    cout << "\n   *******************************************************************************";
    cout << "\n    Route 1 ===>  " << r_1
         << "\n    Route 2 ===>  " << r_2
         << "\n    Route 3 ===>  " << r_3
         << "\n    Route 4 ===>  " << r_4
         << "\n    Route 5 ===>  " << r_5;
    cout << "\n   *******************************************************************************\n";

    cout << endl << endl << endl ;
    system("pause");

}



void Employee::emp_add()
{

    system("cls");
    
    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream empfile;
    empfile.open("empfile.txt", ios::in);


    if(!empfile)
    {
        empfile.close();

        cout << "\nFile does not Exist!!!"
             << "\nAdd New Record\n";
    
        // getting emp info
        cout << "\nEnter Employee Registration Number: ";
        cin >> emp_regno;
        cout << "\nEnter Employee First Name: ";
        cin >> emp_fname;
        cout << "\nEnter Employee Last Name: ";
        cin >> emp_lname;
        cout << "\nEnter Employee Age: ";
        cin >> emp_age;
        cout << "\nEnter Employee CNIC: ";
        cin >> emp_cnic;
        cout << "\nEnter Employee Phone Number: ";
        cin >> emp_phone;
        cout << "\nEnter Employee Address: ";
        cin >> emp_address;
        cout << "\nSelect Employee Department (1-7)"
            << "\n(1.Engineering)(2.Driver)(3.HR)(4.Sales)(5.Planning)(6.Cleaning)(7.Management)"
            << "\n                                                                                :> ";
        int ech;
        dpt:
        cin >> ech;
        switch (ech)
        {
            case 1:
            {
                emp_rankd = "Engineering";
            }break;
            case 2:
            {
                emp_rankd = "Driver";
            }break;
            case 3:
            {
                emp_rankd = "HR";
            }break;
            case 4:
            {
                emp_rankd = "Sales";
            }break;
            case 5:
            {
                emp_rankd = "Planning";
            }break;
            case 6:
            {
                emp_rankd = "Cleaning";
            }break;
            case 7:
            {
                emp_rankd = "Management";
            }break;
            default:
            {
                cout << "\nSelect the Corrent Option (1-7) : ";
                goto dpt;
            }break;
        }
        cout << "\nEnter Employee Salary: ";
        cin >> emp_salary;

        empfile.open("empfile.txt", ios::out | ios::app);
        empfile << emp_regno << " " << emp_fname << " " << emp_lname << " " << emp_age << " " << emp_cnic << " "
                << emp_phone << " " << emp_address << " " << emp_rankd << " " << emp_salary << "\n" ;
        empfile.close();
        cout << "\nInformation Saved...";

    }
    else
    {

        string te_r, te_fn, te_ln, te_a, te_c, te_p, te_ad, te_rk;
        int te_s;

        empfile >> te_r >> te_fn >> te_ln >> te_a >> te_c
                >> te_p >> te_ad >> te_rk >> te_s;

        // empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
        //        >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

        cout << "\nEnter Employee Registration Number: ";
        cin >> emp_regno;

        while(!empfile.eof())
        {
            if(te_r == emp_regno)
            {
                cout << "\nSame Registration Number Already Exists!!!";
                empfile.close();
                goto endfunc;
            }
            empfile >> te_r >> te_fn >> te_ln >> te_a >> te_c
                    >> te_p >> te_ad >> te_rk >> te_s;
        }

        empfile.close();

        cout << "\nEnter Employee First Name: ";
        cin >> emp_fname;
        cout << "\nEnter Employee Last Name: ";
        cin >> emp_lname;
        cout << "\nEnter Employee Age: ";
        cin >> emp_age;
        cout << "\nEnter Employee CNIC: ";
        cin >> emp_cnic;
        cout << "\nEnter Employee Phone Number: ";
        cin >> emp_phone;
        cout << "\nEnter Employee Address: ";
        cin >> emp_address;
        cout << "\nSelect Employee Department (1-7)"
            << "\n(1.Engineering)(2.Driver)(3.HR)(4.Sales)(5.Planning)(6.Cleaning)(7.Management)"
            << "\n                                                                                :> ";
        int ech;
        dpto:
        cin >> ech;
        switch (ech)
        {
            case 1:
            {
                emp_rankd = "Engineering";
            }break;
            case 2:
            {
                emp_rankd = "Driver";
            }break;
            case 3:
            {
                emp_rankd = "HR";
            }break;
            case 4:
            {
                emp_rankd = "Sales";
            }break;
            case 5:
            {
                emp_rankd = "Planning";
            }break;
            case 6:
            {
                emp_rankd = "Cleaning";
            }break;
            case 7:
            {
                emp_rankd = "Management";
            }break;
            default:
            {
                cout << "\nSelect the Corrent Option (1-7) : ";
                goto dpto;
            }break;
        }
        cout << "\nEnter Employee Salary: ";
        cin >> emp_salary;

        empfile.open("empfile.txt", ios::out | ios::app);
        empfile << emp_regno << " " << emp_fname << " " << emp_lname << " " << emp_age << " " << emp_cnic << " "
                << emp_phone << " " << emp_address << " " << emp_rankd << " " << emp_salary << "\n" ;
        empfile.close();
        cout << "\nInformation Saved...";


        endfunc:
        cout << endl << endl << endl ;
        system("pause");
    }


}



void Employee::emp_showall()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream empfile;

    empfile.open("empfile.txt", ios::in);

    if(!empfile)
    {
        cout << "\nFile does not Exist!!!";
        empfile.close();
        goto endfunc;
    }

    empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
            >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

    cout << "\n\t\t\tAll Employees\n";


    while(!empfile.eof())
    {

        cout << "\n------------------------------------------------------------------------";

        cout << "\nEmployee Registration Number: " << emp_regno ;

        cout << "\n------------------------------------------------------------------------";

        cout << "\nFirst Name: " << emp_fname << "\t\tLast Name: " << emp_lname << "\t\tAge: " << emp_age
    
             << "\nCNIC: " << emp_cnic << "\t\tPhone Number: " << emp_phone
    
             << "\nAddress: " << emp_address
    
             << "\nDepartment: " << emp_rankd << "\t\tSalary: " << emp_salary ;

        cout << "\n------------------------------------------------------------------------\n\n";

        empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

    }

    empfile.close();

    
    endfunc:
    cout << endl << endl << endl ;
    system("pause");

}



void Employee::emp_search()
{


    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream empfile;

    empfile.open("empfile.txt", ios::in);

    int found = 0;

    if(!empfile)
    {
        empfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {
        
        string te_reg;

        int found = 0;

        empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;


        cout << "\nEnter Employee Registration Number : ";
        cin >> te_reg;

        while(!empfile.eof())
        {

            if(emp_regno == te_reg)
            {
                
                cout << "\n\n\nEmployee Found!!!";

                cout << "\n---------------------------------------------------";

                cout << "\nEmployee Registration Number: " << emp_regno

                     << "\nFirst Name: " << emp_fname
             
                     << "\nLast Name: " << emp_lname
             
                     << "\nAge: " << emp_age
             
                     << "\nCNIC: " << emp_cnic
             
                     << "\nPhone Number: " << emp_phone
             
                     << "\nAddress: " << emp_address
             
                     << "\nDepartment: " << emp_rankd
             
                     << "\nSalary: " << emp_salary ;

                cout << "\n---------------------------------------------------\n\n";

                found++;

            }

            empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                    >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

        }

        empfile.close();

        if(found == 0)
        {
        cout << "\n\nEmployee could not be found!!!\n";
        }

    }

    cout << endl << endl << endl ;
    system("pause");

}



void Employee::emp_update()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream empfile;

    empfile.open("empfile.txt", ios::in);

    int found = 0;

    if(!empfile)
    {
        empfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {

        string te_reg, del_reg;

        int found = 0;

        empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;


        cout << "\nEnter Employee Registration Number : ";
        cin >> te_reg;

        del_reg = te_reg;

        while(!empfile.eof())
        {

            if(emp_regno == te_reg)
            {
                
                cout << "\n\n\nEmployee Found!!!";

                cout << "\n---------------------------------------------------";

                cout << "\nEmployee Registration Number: " << emp_regno

                     << "\nFirst Name: " << emp_fname
             
                     << "\nLast Name: " << emp_lname
             
                     << "\nAge: " << emp_age
             
                     << "\nCNIC: " << emp_cnic
             
                     << "\nPhone Number: " << emp_phone
             
                     << "\nAddress: " << emp_address
             
                     << "\nDepartment: " << emp_rankd
             
                     << "\nSalary: " << emp_salary ;

                cout << "\n---------------------------------------------------\n\n";

                found++;

                empfile.close();

                cout << "\n\nEnter New Information ";


                cout << "\nEnter Employee Registration Number: ";
                cin >> emp_regno;
                cout << "\nEnter Employee First Name: ";
                cin >> emp_fname;
                cout << "\nEnter Employee Last Name: ";
                cin >> emp_lname;
                cout << "\nEnter Employee Age: ";
                cin >> emp_age;
                cout << "\nEnter Employee CNIC: ";
                cin >> emp_cnic;
                cout << "\nEnter Employee Phone Number: ";
                cin >> emp_phone;
                cout << "\nEnter Employee Address: ";
                cin >> emp_address;
                cout << "\nSelect Employee Department (1-7)"
                    << "\n(1.Engineering)(2.Driver)(3.HR)(4.Sales)(5.Planning)(6.Cleaning)(7.Management)"
                    << "\n                                                                                :> ";
                int ech;
                dpt:
                cin >> ech;
                switch (ech)
                {
                    case 1:
                    {
                        emp_rankd = "Engineering";
                    }break;
                    case 2:
                    {
                        emp_rankd = "Driver";
                    }break;
                    case 3:
                    {
                        emp_rankd = "HR";
                    }break;
                    case 4:
                    {
                        emp_rankd = "Sales";
                    }break;
                    case 5:
                    {
                        emp_rankd = "Planning";
                    }break;
                    case 6:
                    {
                        emp_rankd = "Cleaning";
                    }break;
                    case 7:
                    {
                        emp_rankd = "Management";
                    }break;
                    default:
                    {
                        cout << "\nSelect the Corrent Option (1-7) : ";
                        goto dpt;
                    }break;
                }
                cout << "\nEnter Employee Salary: ";
                cin >> emp_salary;


                fstream tempfile;

                tempfile.open("tempfile.txt", ios::out | ios::app);
                tempfile << emp_regno << " " << emp_fname << " " << emp_lname << " " << emp_age << " " << emp_cnic << " "
                         << emp_phone << " " << emp_address << " " << emp_rankd << " " << emp_salary << "\n" ;
                
                empfile.open("empfile.txt", ios::in);

                empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                        >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

                while(!empfile.eof())
                {

                    if(emp_regno != del_reg)
                    {
                    tempfile << emp_regno << " " << emp_fname << " " << emp_lname << " " << emp_age << " " << emp_cnic << " "
                             << emp_phone << " " << emp_address << " " << emp_rankd << " " << emp_salary << "\n" ;
                    }

                    empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                            >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

                }

                empfile.close();
                tempfile.close();

                remove("empfile.txt");
                rename("tempfile.txt", "empfile.txt");

                cout << "\n\nUpdate Successful!!!";


                {
                    cout << "\ndeleting ride for this employee...";

                    fstream ridfile;

                    ridfile.open("ridfile.txt", ios::in);

                    int found = 0;

                    if(!ridfile)
                    {
                        ridfile.close();
                        cout << "\nride file does not exist...";
                    }
                    else
                    {

                        string rid_regno;
                        string rid_route;

                        string bus_regno;
                        string bus_brand;
                        string bus_model;
                        string bus_color;
                        string bus_g_weight;
                        string bus_manu_date;
                        int bus_cost;
                        int bus_pes_cap;
                        string bus_eng;
                        string bus_eng_power;
                        string bus_f_type;
                        int bus_f_cap;
                        float bus_mileage;


                        int ridfound = 0;

                        ridfile >> rid_regno     >> rid_route
                                >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        while(!ridfile.eof())
                        {

                            if(te_reg == emp_regno)
                            {
                                
                                cout << "\n\n\nRide Found!!!";

                                cout << "\n=====================================================================";
                                cout << "\nRide Number : " << rid_regno;
                                cout << "\nRoute : " << rid_route;
                                cout << "\n---------------------------------------------------------------------";
                                cout << "\nEmployee Registration Number: " << emp_regno
                                    << "\nFirst Name: " << emp_fname
                                    << "\nLast Name: " << emp_lname
                                    << "\nAge: " << emp_age
                                    << "\nCNIC: " << emp_cnic
                                    << "\nPhone Number: " << emp_phone
                                    << "\nAddress: " << emp_address
                                    << "\nDepartment: " << emp_rankd
                                    << "\nSalary: " << emp_salary ;
                                cout << "\n---------------------------------------------------------------------";
                                cout << "\nBus Registration Number: " << bus_regno
                                    << "\nBrand: " << bus_brand 
                                    << "\nModel: " << bus_model 
                                    << "\nColor: " << bus_color
                                    << "\nGross Weight: " << bus_g_weight
                                    << "\nManufacturing date: " << bus_manu_date
                                    << "\nCost: " << bus_cost
                                    << "\nPassenger Capacity: " << bus_pes_cap
                                    << "\nEngine Number: " << bus_eng 
                                    << "\nEngine Power: " << bus_eng_power
                                    << "\nFuel Type: " << bus_f_type 
                                    << "\nFuel Capacity" << bus_f_cap
                                    << "\nMilage(kml): " << bus_mileage ;
                                cout << "\n=====================================================================\n\n";

                                ridfound++;

                                ridfile.close();

                                cout << "\n\nDeleting Information!!!";


                                fstream tempfile;

                                tempfile.open("tempfile.txt", ios::out | ios::app);

                                ridfile.open("ridfile.txt", ios::in);
                                

                                ridfile >> rid_regno     >> rid_route
                                        >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                        >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                        >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                        >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                        >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                                while(!ridfile.eof())
                                {

                                    if(rid_regno != del_reg)
                                    {
                                        tempfile << rid_regno     << " " << rid_route   << " "
                                                << emp_regno     << " " << emp_fname   << " " << emp_lname   << " " << emp_age    << " " << emp_cnic      << " "
                                                << emp_phone     << " " << emp_address << " " << emp_rankd   << " " << emp_salary << " "
                                                << bus_regno     << " " << bus_brand   << " " << bus_model   << " " << bus_color  << " " << bus_g_weight  << " "
                                                << bus_manu_date << " " << bus_cost    << " " << bus_pes_cap << " " << bus_eng    << " " << bus_eng_power << " "
                                                << bus_f_type    << " " << bus_f_cap   << " " << bus_mileage << "\n" ;
                                    }

                                    ridfile >> rid_regno     >> rid_route
                                            >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                            >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                            >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                            >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                            >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                                }

                                ridfile.close();
                                tempfile.close();

                                remove("ridfile.txt");
                                rename("tempfile.txt", "ridfile.txt");

                                cout << "\n\nDeleted Successfully!!!";

                            }

                            ridfile >> rid_regno     >> rid_route
                                    >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                    >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                    >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                    >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                    >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        }

                        if(ridfound == 0)
                        {
                        cout << "\nride could not be found...\n";
                        }

                    }

                }


            }

            empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                    >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

        }


        if(found == 0)
        {
        cout << "\n\nEmployee could not be found!!!\n";
        }

    }


    cout << endl << endl << endl ;
    system("pause");

}



void Employee::emp_delete()
{


    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream empfile;

    empfile.open("empfile.txt", ios::in);

    int found = 0;

    if(!empfile)
    {
        empfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {

        string te_reg, del_reg;

        int found = 0;

        empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;


        cout << "\nEnter Employee Registration Number : ";
        cin >> te_reg;

        del_reg = te_reg;

        while(!empfile.eof())
        {

            if(emp_regno == te_reg)
            {
                
                cout << "\n\n\nEmployee Found!!!";

                cout << "\n---------------------------------------------------";

                cout << "\nEmployee Registration Number: " << emp_regno

                     << "\nFirst Name: " << emp_fname
             
                     << "\nLast Name: " << emp_lname
             
                     << "\nAge: " << emp_age
             
                     << "\nCNIC: " << emp_cnic
             
                     << "\nPhone Number: " << emp_phone
             
                     << "\nAddress: " << emp_address
             
                     << "\nDepartment: " << emp_rankd
             
                     << "\nSalary: " << emp_salary ;

                cout << "\n---------------------------------------------------\n\n";

                found++;

                empfile.close();

                cout << "\n\nDeleting Information!!!";


                fstream tempfile;

                tempfile.open("tempfile.txt", ios::out | ios::app);

                empfile.open("empfile.txt", ios::in);
                

                empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                        >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

                while(!empfile.eof())
                {

                    if(emp_regno != del_reg)
                    {
                    tempfile << emp_regno << " " << emp_fname << " " << emp_lname << " " << emp_age << " " << emp_cnic << " "
                             << emp_phone << " " << emp_address << " " << emp_rankd << " " << emp_salary << "\n" ;
                    }

                    empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                            >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

                }

                empfile.close();
                tempfile.close();

                remove("empfile.txt");
                rename("tempfile.txt", "empfile.txt");

                cout << "\n\nDeleted Successfully!!!";


                {
                    cout << "\ndeleting ride for this employee...";

                    fstream ridfile;

                    ridfile.open("ridfile.txt", ios::in);

                    int found = 0;

                    if(!ridfile)
                    {
                        ridfile.close();
                        cout << "\nride file does not exist...";
                    }
                    else
                    {

                        string rid_regno;
                        string rid_route;

                        string bus_regno;
                        string bus_brand;
                        string bus_model;
                        string bus_color;
                        string bus_g_weight;
                        string bus_manu_date;
                        int bus_cost;
                        int bus_pes_cap;
                        string bus_eng;
                        string bus_eng_power;
                        string bus_f_type;
                        int bus_f_cap;
                        float bus_mileage;


                        int ridfound = 0;

                        ridfile >> rid_regno     >> rid_route
                                >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        while(!ridfile.eof())
                        {

                            if(te_reg == emp_regno)
                            {
                                
                                cout << "\n\n\nRide Found!!!";

                                cout << "\n=====================================================================";
                                cout << "\nRide Number : " << rid_regno;
                                cout << "\nRoute : " << rid_route;
                                cout << "\n---------------------------------------------------------------------";
                                cout << "\nEmployee Registration Number: " << emp_regno
                                    << "\nFirst Name: " << emp_fname
                                    << "\nLast Name: " << emp_lname
                                    << "\nAge: " << emp_age
                                    << "\nCNIC: " << emp_cnic
                                    << "\nPhone Number: " << emp_phone
                                    << "\nAddress: " << emp_address
                                    << "\nDepartment: " << emp_rankd
                                    << "\nSalary: " << emp_salary ;
                                cout << "\n---------------------------------------------------------------------";
                                cout << "\nBus Registration Number: " << bus_regno
                                    << "\nBrand: " << bus_brand 
                                    << "\nModel: " << bus_model 
                                    << "\nColor: " << bus_color
                                    << "\nGross Weight: " << bus_g_weight
                                    << "\nManufacturing date: " << bus_manu_date
                                    << "\nCost: " << bus_cost
                                    << "\nPassenger Capacity: " << bus_pes_cap
                                    << "\nEngine Number: " << bus_eng 
                                    << "\nEngine Power: " << bus_eng_power
                                    << "\nFuel Type: " << bus_f_type 
                                    << "\nFuel Capacity" << bus_f_cap
                                    << "\nMilage(kml): " << bus_mileage ;
                                cout << "\n=====================================================================\n\n";

                                ridfound++;

                                ridfile.close();

                                cout << "\n\nDeleting Information!!!";


                                fstream tempfile;

                                tempfile.open("tempfile.txt", ios::out | ios::app);

                                ridfile.open("ridfile.txt", ios::in);
                                

                                ridfile >> rid_regno     >> rid_route
                                        >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                        >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                        >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                        >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                        >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                                while(!ridfile.eof())
                                {

                                    if(rid_regno != del_reg)
                                    {
                                        tempfile << rid_regno     << " " << rid_route   << " "
                                                << emp_regno     << " " << emp_fname   << " " << emp_lname   << " " << emp_age    << " " << emp_cnic      << " "
                                                << emp_phone     << " " << emp_address << " " << emp_rankd   << " " << emp_salary << " "
                                                << bus_regno     << " " << bus_brand   << " " << bus_model   << " " << bus_color  << " " << bus_g_weight  << " "
                                                << bus_manu_date << " " << bus_cost    << " " << bus_pes_cap << " " << bus_eng    << " " << bus_eng_power << " "
                                                << bus_f_type    << " " << bus_f_cap   << " " << bus_mileage << "\n" ;
                                    }

                                    ridfile >> rid_regno     >> rid_route
                                            >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                            >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                            >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                            >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                            >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                                }

                                ridfile.close();
                                tempfile.close();

                                remove("ridfile.txt");
                                rename("tempfile.txt", "ridfile.txt");

                                cout << "\n\nDeleted Successfully!!!";

                            }

                            ridfile >> rid_regno     >> rid_route
                                    >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                    >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                    >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                    >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                    >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        }

                        if(ridfound == 0)
                        {
                        cout << "\nride could not be found...\n";
                        }

                    }

                }

            }

            empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                    >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

        }


        if(found == 0)
        {
        cout << "\n\nEmployee could not be found!!!\n";
        }

    }


    cout << endl << endl << endl ;
    system("pause");

}



void Employee::emp_allinfo()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    cout << "\n\n\t\t\tEmployees Information\n\n";


    int eng=0, dri=0, hr=0, sal=0, pla=0, cle=0, mana=0 ;
    int engp=0, drip=0, hrp=0, salp=0, plap=0, clep=0, manap=0 ;
    int totalemp=0 ;
    int totalpay=0 ;

    fstream empfile;

    empfile.open("empfile.txt", ios::in);

    if(!empfile)
    {
        empfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {

        empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;


        while(!empfile.eof())
        {

            if(emp_rankd == "Engineering")
            {
                eng++ ;
                engp += emp_salary ;
            }
            else if(emp_rankd == "Driver")
            {
                dri++ ;
                drip += emp_salary ;
            }
            else if(emp_rankd == "HR")
            {
                hr++ ;
                hrp += emp_salary ;
            }
            else if(emp_rankd == "Sales")
            {
                sal++ ;
                salp += emp_salary ;
            }
            else if(emp_rankd == "Planning")
            {
                pla++ ;
                plap += emp_salary ;
            }
            else if(emp_rankd == "Cleaning")
            {
                cle++ ;
                clep += emp_salary ;
            }
            else if(emp_rankd == "Management")
            {
                mana++ ;
                manap += emp_salary ;
            }

            totalemp++ ;

            totalpay += emp_salary ;


            empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                    >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

        }

        empfile.close();

    }

    cout << "\n=============================================================";
    cout << "\n-----------------------------EMPLOYEES----------PAYMENTS-----";
    cout << "\nTotal Number of Employees    : " << totalemp << "\t\t: " << totalpay ;
    cout << "\n-------------------------------------------------------------";
    cout << "\nTotal Number of Engineers    : " << eng  << "\t\t: " << engp
         << "\nTotal Number of Drivers      : " << dri  << "\t\t: " << drip
         << "\nTotal Number of HRs          : " << hr   << "\t\t: " << hrp
         << "\nTotal Number of Sales Person : " << sal  << "\t\t: " << salp
         << "\nTotal Number of Planners     : " << pla  << "\t\t: " << plap
         << "\nTotal Number of Cleaners     : " << cle  << "\t\t: " << clep
         << "\nTotal Number of Managers     : " << mana << "\t\t: " << manap ;
    cout << "\n=============================================================\n\n";

    
    cout << endl << endl << endl ;
    system("pause");

}



void Bus::bus_add()
{

    system("cls");
    
    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream busfile;
    busfile.open("busfile.txt", ios::in);


    if(!busfile)
    {
        busfile.close();

        cout << "\nFile does not Exist!!!"
             << "\nAdd New Record\n";
    
        // getting bus info
        cout << "\nEnter Bus Registration Number: ";
        cin >> bus_regno;
        cout << "\nEnter Bus Brand : ";
        cin >> bus_brand;
        cout << "\nEnter Bus Model : ";
        cin >> bus_model;
        cout << "\nEnter Bus Color: ";
        cin >> bus_color;
        cout << "\nEnter Bus Gross Weight: ";
        cin >> bus_g_weight;
        cout << "\nEnter Bus Manufacturing date: ";
        cin >> bus_manu_date;
        cout << "\nEnter Bus Cost: ";
        cin >> bus_cost;
        pescap:
        cout << "\nEnter Bus Passenger Capacity: ";
        cin >> bus_pes_cap;
        if(bus_pes_cap < 10)
        {
            cout << "\nError...Bus should have atleast 10 seats...";
            goto pescap;
        }
        else if(bus_pes_cap > 50)
        {
            cout << "\nError...Bus should not have more than 50 seats...";
            goto pescap;
        }
        cout << "\nEnter Bus Engine Number : ";
        cin >> bus_eng;
        cout << "\nEnter Bus Engine Power: ";
        cin >> bus_eng_power;
        cout << "\nEnter Bus Fuel Type: ";
        cin >> bus_f_type;
        cout << "\nEnter Bus Fuel Capacity: ";
        cin >> bus_f_cap;
        cout << "\nEnter Bus Mileage(kml): ";
        cin >> bus_mileage;

        busfile.open("busfile.txt", ios::out | ios::app);
        busfile << bus_regno     << " " << bus_brand << " " << bus_model   << " " << bus_color << " " << bus_g_weight  << " "
                << bus_manu_date << " " << bus_cost  << " " << bus_pes_cap << " " << bus_eng   << " " << bus_eng_power << " "
                << bus_f_type    << " " << bus_f_cap << " " << bus_mileage << " " << "\n" ;
        busfile.close();
        cout << "\nInformation Saved...";

    }
    else
    {

        string tb_regno, tbbra, tbmod, tbcol, tbgw, tbmanud, tbeng, tbengp, tbft ;
        int tbcost, tbpc, tbfc;
        float tbmil;

        busfile >> tb_regno >> tbbra  >> tbmod >> tbcol >> tbgw 
                >> tbmanud  >> tbcost >> tbpc  >> tbeng >> tbengp 
                >> tbft     >> tbfc   >> tbmil ; 


        cout << "\nEnter Bus Registration Number: ";
        cin >> bus_regno;

        while(!busfile.eof())
        {
            if(tb_regno == bus_regno)
            {
                cout << "\nSame Registration Number Already Exists!!!";
                busfile.close();
                goto endfunc;
            }
            
            busfile >> tb_regno >> tbbra  >> tbmod >> tbcol >> tbgw 
                    >> tbmanud  >> tbcost >> tbpc  >> tbeng >> tbengp 
                    >> tbft     >> tbfc   >> tbmil ;  
        }

        busfile.close();

        cout << "\nEnter Bus Brand : ";
        cin >> bus_brand;
        cout << "\nEnter Bus Model : ";
        cin >> bus_model;
        cout << "\nEnter Bus Color: ";
        cin >> bus_color;
        cout << "\nEnter Bus Gross Weight: ";
        cin >> bus_g_weight;
        cout << "\nEnter Bus Manufacturing date: ";
        cin >> bus_manu_date;
        cout << "\nEnter Bus Cost: ";
        cin >> bus_cost;
        pescapp:
        cout << "\nEnter Bus Passenger Capacity: ";
        cin >> bus_pes_cap;
        if(bus_pes_cap < 10)
        {
            cout << "\nError...Bus should have atleast 10 seats...";
            goto pescapp;
        }
        else if(bus_pes_cap > 50)
        {
            cout << "\nError...Bus should not have more than 50 seats...";
            goto pescapp;
        }
        cout << "\nEnter Bus Engine Number : ";
        cin >> bus_eng;
        cout << "\nEnter Bus Engine Power: ";
        cin >> bus_eng_power;
        cout << "\nEnter Bus Fuel Type: ";
        cin >> bus_f_type;
        cout << "\nEnter Bus Fuel Capacity: ";
        cin >> bus_f_cap;
        cout << "\nEnter Bus Mileage(kml): ";
        cin >> bus_mileage;

        busfile.open("busfile.txt", ios::out | ios::app);
        busfile << bus_regno     << " " << bus_brand << " " << bus_model   << " " << bus_color << " " << bus_g_weight  << " "
                << bus_manu_date << " " << bus_cost  << " " << bus_pes_cap << " " << bus_eng   << " " << bus_eng_power << " "
                << bus_f_type    << " " << bus_f_cap << " " << bus_mileage << " " << "\n" ;
        busfile.close();
        cout << "\nInformation Saved...";


        endfunc:
        cout << endl << endl << endl ;
        system("pause");
    }

}



void Bus::bus_showall()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream busfile;

    busfile.open("busfile.txt", ios::in);

    if(!busfile)
    {
        cout << "\nFile does not Exist!!!";
        busfile.close();
        goto endfunc;
    }

    busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
            >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
            >> bus_f_type    >> bus_f_cap >> bus_mileage ;

    cout << "\n\t\t\tAll Busses\n\n";


    while(!busfile.eof())
    {

        cout << "\n==========================================";

        cout << "\nBus Registration Number: " << bus_regno ;

        cout << "\n------------------------------------------";
             
        cout << "\nBrand: " << bus_brand 
        
             << "\nModel: " << bus_model 
             
             << "\nColor: " << bus_color
    
             << "\nGross Weight: " << bus_g_weight

             << "\nManufacturing date: " << bus_manu_date
    
             << "\nCost: " << bus_cost
    
             << "\nPassenger Capacity: " << bus_pes_cap
    
             << "\nEngine Number: " << bus_eng 
             
             << "\nEngine Power: " << bus_eng_power
    
             << "\nFuel Type: " << bus_f_type 
             
             << "\nFuel Capacity" << bus_f_cap
    
             << "\nMilage(kml): " << bus_mileage ;

        cout << "\n==========================================\n\n";

        busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                >> bus_f_type    >> bus_f_cap >> bus_mileage ;

    }

    busfile.close();

    
    endfunc:
    cout << endl << endl << endl ;
    system("pause");

}



void Bus::bus_search()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream busfile;

    busfile.open("busfile.txt", ios::in);

    int found = 0;

    if(!busfile)
    {
        busfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {
        
        string tb_regno;

        int found = 0;

        busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                >> bus_f_type    >> bus_f_cap >> bus_mileage ;


        cout << "\nEnter Bus Registration Number : ";
        cin >> tb_regno;

        while(!busfile.eof())
        {

            if(bus_regno == tb_regno)
            {
                
                cout << "\n\n\nBus Found!!!\n";

                cout << "\n------------------------------------------";

                cout << "\nBus Registration Number: " << bus_regno ;

                cout << "\nBrand: " << bus_brand 
                
                     << "\nModel: " << bus_model 
                     
                     << "\nColor: " << bus_color
             
                     << "\nGross Weight: " << bus_g_weight
 
                     << "\nManufacturing date: " << bus_manu_date
             
                     << "\nCost: " << bus_cost
             
                     << "\nPassenger Capacity: " << bus_pes_cap
             
                     << "\nEngine Number: " << bus_eng 
                     
                     << "\nEngine Power: " << bus_eng_power
             
                     << "\nFuel Type: " << bus_f_type 
                     
                     << "\nFuel Capacity" << bus_f_cap
             
                     << "\nMilage(kml): " << bus_mileage ;

                cout << "\n------------------------------------------";

                found++;

            }

            busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                    >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                    >> bus_f_type    >> bus_f_cap >> bus_mileage ;

        }

        busfile.close();

        if(found == 0)
        {
        cout << "\n\nBus could not be found!!!\n";
        }

    }

    cout << endl << endl << endl ;
    system("pause");

}



void Bus::bus_update()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream busfile;

    busfile.open("busfile.txt", ios::in);

    int found = 0;

    if(!busfile)
    {
        busfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {

        string tb_regno, del_regno;

        int found = 0;

        busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                >> bus_f_type    >> bus_f_cap >> bus_mileage ;


        cout << "\nEnter Bus Registration Number : ";
        cin >> tb_regno;

        del_regno = tb_regno;

        while(!busfile.eof())
        {

            if(bus_regno == tb_regno)
            {
                
                cout << "\n\n\nBus Found!!!\n";

               cout << "\n------------------------------------------";

                cout << "\nBus Registration Number: " << bus_regno ;

                cout << "\nBrand: " << bus_brand 
                
                     << "\nModel: " << bus_model 
                     
                     << "\nColor: " << bus_color
             
                     << "\nGross Weight: " << bus_g_weight
 
                     << "\nManufacturing date: " << bus_manu_date
             
                     << "\nCost: " << bus_cost
             
                     << "\nPassenger Capacity: " << bus_pes_cap
             
                     << "\nEngine Number: " << bus_eng 
                     
                     << "\nEngine Power: " << bus_eng_power
             
                     << "\nFuel Type: " << bus_f_type 
                     
                     << "\nFuel Capacity" << bus_f_cap
             
                     << "\nMilage(kml): " << bus_mileage ;

                cout << "\n------------------------------------------";

                found++;

                busfile.close();

                cout << "\n\nEnter New Information ";

                cout << "\nEnter Bus Registration Number: ";
                cin >> bus_regno;
                cout << "\nEnter Bus Brand : ";
                cin >> bus_brand;
                cout << "\nEnter Bus Model : ";
                cin >> bus_model;
                cout << "\nEnter Bus Color: ";
                cin >> bus_color;
                cout << "\nEnter Bus Gross Weight: ";
                cin >> bus_g_weight;
                cout << "\nEnter Bus Manufacturing date: ";
                cin >> bus_manu_date;
                cout << "\nEnter Bus Cost: ";
                cin >> bus_cost;
                pesco:
                cout << "\nEnter Bus Passenger Capacity: ";
                cin >> bus_pes_cap;
                if(bus_pes_cap < 10)
                {
                    cout << "\nError...Bus should have atleast 10 seats...";
                    goto pesco;
                }
                else if(bus_pes_cap > 50)
                {
                    cout << "\nError...Bus should not have more than 50 seats...";
                    goto pesco;
                }
                cout << "\nEnter Bus Engine Number : ";
                cin >> bus_eng;
                cout << "\nEnter Bus Engine Power: ";
                cin >> bus_eng_power;
                cout << "\nEnter Bus Fuel Type: ";
                cin >> bus_f_type;
                cout << "\nEnter Bus Fuel Capacity: ";
                cin >> bus_f_cap;
                cout << "\nEnter Bus Mileage(kml): ";
                cin >> bus_mileage;



                fstream tempfile;

                tempfile.open("tempfile.txt", ios::out | ios::app);
                tempfile << bus_regno     << " " << bus_brand << " " << bus_model   << " " << bus_color << " " << bus_g_weight  << " "
                         << bus_manu_date << " " << bus_cost  << " " << bus_pes_cap << " " << bus_eng   << " " << bus_eng_power << " "
                         << bus_f_type    << " " << bus_f_cap << " " << bus_mileage << " " << "\n" ;
                
                busfile.open("busfile.txt", ios::in);

                busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                        >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                        >> bus_f_type    >> bus_f_cap >> bus_mileage ;

                while(!busfile.eof())
                {

                if(bus_regno != del_regno)
                {    
                tempfile << bus_regno     << " " << bus_brand << " " << bus_model   << " " << bus_color << " " << bus_g_weight  << " "
                         << bus_manu_date << " " << bus_cost  << " " << bus_pes_cap << " " << bus_eng   << " " << bus_eng_power << " "
                         << bus_f_type    << " " << bus_f_cap << " " << bus_mileage << " " << "\n" ;
                }

                busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                        >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                        >> bus_f_type    >> bus_f_cap >> bus_mileage ;

                }

                busfile.close();
                tempfile.close();

                remove("busfile.txt");
                rename("tempfile.txt", "busfile.txt");

                cout << "\n\nUpdate Successful!!!";


                {
                    cout << "\ndeleting ride for this bus...";

                    fstream ridfile;

                    ridfile.open("ridfile.txt", ios::in);

                    int found = 0;

                    if(!ridfile)
                    {
                        ridfile.close();
                        cout << "\nride file does not exist...";
                    }
                    else
                    {

                        string rid_regno;
                        string rid_route;

                        string bus_regno;
                        string bus_brand;
                        string bus_model;
                        string bus_color;
                        string bus_g_weight;
                        string bus_manu_date;
                        int bus_cost;
                        int bus_pes_cap;
                        string bus_eng;
                        string bus_eng_power;
                        string bus_f_type;
                        int bus_f_cap;
                        float bus_mileage;

                        string emp_regno;
                        string emp_fname;
                        string emp_lname;
                        string emp_age;
                        string emp_cnic;
                        string emp_phone;
                        string emp_address;
                        int emp_salary;
                        string emp_rankd;


                        int ridfound = 0;

                        ridfile >> rid_regno     >> rid_route
                                >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        while(!ridfile.eof())
                        {

                            if(tb_regno == bus_regno)
                            {
                                
                                cout << "\n\n\nRide Found!!!";

                                cout << "\n=====================================================================";
                                cout << "\nRide Number : " << rid_regno;
                                cout << "\nRoute : " << rid_route;
                                cout << "\n---------------------------------------------------------------------";
                                cout << "\nEmployee Registration Number: " << emp_regno
                                    << "\nFirst Name: " << emp_fname
                                    << "\nLast Name: " << emp_lname
                                    << "\nAge: " << emp_age
                                    << "\nCNIC: " << emp_cnic
                                    << "\nPhone Number: " << emp_phone
                                    << "\nAddress: " << emp_address
                                    << "\nDepartment: " << emp_rankd
                                    << "\nSalary: " << emp_salary ;
                                cout << "\n---------------------------------------------------------------------";
                                cout << "\nBus Registration Number: " << bus_regno
                                    << "\nBrand: " << bus_brand 
                                    << "\nModel: " << bus_model 
                                    << "\nColor: " << bus_color
                                    << "\nGross Weight: " << bus_g_weight
                                    << "\nManufacturing date: " << bus_manu_date
                                    << "\nCost: " << bus_cost
                                    << "\nPassenger Capacity: " << bus_pes_cap
                                    << "\nEngine Number: " << bus_eng 
                                    << "\nEngine Power: " << bus_eng_power
                                    << "\nFuel Type: " << bus_f_type 
                                    << "\nFuel Capacity" << bus_f_cap
                                    << "\nMilage(kml): " << bus_mileage ;
                                cout << "\n=====================================================================\n\n";

                                ridfound++;

                                ridfile.close();

                                cout << "\n\nDeleting Information!!!";


                                fstream tempfile;

                                tempfile.open("tempfile.txt", ios::out | ios::app);

                                ridfile.open("ridfile.txt", ios::in);
                                

                                ridfile >> rid_regno     >> rid_route
                                        >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                        >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                        >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                        >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                        >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                                while(!ridfile.eof())
                                {

                                    if(tb_regno != bus_regno)
                                    {
                                        tempfile << rid_regno     << " " << rid_route   << " "
                                                 << emp_regno     << " " << emp_fname   << " " << emp_lname   << " " << emp_age    << " " << emp_cnic      << " "
                                                 << emp_phone     << " " << emp_address << " " << emp_rankd   << " " << emp_salary << " "
                                                 << bus_regno     << " " << bus_brand   << " " << bus_model   << " " << bus_color  << " " << bus_g_weight  << " "
                                                 << bus_manu_date << " " << bus_cost    << " " << bus_pes_cap << " " << bus_eng    << " " << bus_eng_power << " "
                                                 << bus_f_type    << " " << bus_f_cap   << " " << bus_mileage << "\n" ;
                                    }

                                    ridfile >> rid_regno     >> rid_route
                                            >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                            >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                            >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                            >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                            >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                                }

                                ridfile.close();
                                tempfile.close();

                                remove("ridfile.txt");
                                rename("tempfile.txt", "ridfile.txt");

                                cout << "\n\nDeleted Successfully!!!";

                            }

                            ridfile >> rid_regno     >> rid_route
                                    >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                    >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                    >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                    >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                    >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        }

                        if(ridfound == 0)
                        {
                        cout << "\nride could not be found...\n";
                        }

                    }

                }




            }

                busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                        >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                        >> bus_f_type    >> bus_f_cap >> bus_mileage ;

        }

        if(found == 0)
        {
        cout << "\n\nBus could not be found!!!\n";
        }

    }

    cout << endl << endl << endl ;
    system("pause");

}



void Bus::bus_delete()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream busfile;

    busfile.open("busfile.txt", ios::in);

    int found = 0;

    if(!busfile)
    {
        busfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {

        string tb_regno, del_regno;

        int found = 0;

        busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                >> bus_f_type    >> bus_f_cap >> bus_mileage ;


        cout << "\nEnter Bus Registration Number : ";
        cin >> tb_regno;

        del_regno = tb_regno;

        while(!busfile.eof())
        {

            if(bus_regno == tb_regno)
            {
                
                cout << "\n\n\nBus Found!!!";

                cout << "\n---------------------------------------------------";

                cout << "\nBus Registration Number: " << bus_regno ;

                cout << "\nBrand: " << bus_brand 
                
                     << "\nModel: " << bus_model 
                     
                     << "\nColor: " << bus_color
             
                     << "\nGross Weight: " << bus_g_weight
 
                     << "\nManufacturing date: " << bus_manu_date
             
                     << "\nCost: " << bus_cost
             
                     << "\nPassenger Capacity: " << bus_pes_cap
             
                     << "\nEngine Number: " << bus_eng 
                     
                     << "\nEngine Power: " << bus_eng_power
             
                     << "\nFuel Type: " << bus_f_type 
                     
                     << "\nFuel Capacity" << bus_f_cap
             
                     << "\nMilage(kml): " << bus_mileage ;

                cout << "\n---------------------------------------------------\n\n";

                found++;

                busfile.close();

                cout << "\n\nDeleting Information!!!";


                fstream tempfile;

                tempfile.open("tempfile.txt", ios::out | ios::app);

                busfile.open("busfile.txt", ios::in);
                

                busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                        >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                        >> bus_f_type    >> bus_f_cap >> bus_mileage ;

                while(!busfile.eof())
                {

                    if(bus_regno != del_regno)
                    {
                    tempfile << bus_regno     << " " << bus_brand << " " << bus_model   << " " << bus_color << " " << bus_g_weight  << " "
                             << bus_manu_date << " " << bus_cost  << " " << bus_pes_cap << " " << bus_eng   << " " << bus_eng_power << " "
                             << bus_f_type    << " " << bus_f_cap << " " << bus_mileage << " " << "\n" ;
                    }

                    busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                            >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                            >> bus_f_type    >> bus_f_cap >> bus_mileage ;
                }

                busfile.close();
                tempfile.close();

                remove("busfile.txt");
                rename("tempfile.txt", "busfile.txt");

                cout << "\n\nDeleted Successfully!!!";


                {
                    cout << "\ndeleting ride for this bus...";

                    fstream ridfile;

                    ridfile.open("ridfile.txt", ios::in);

                    int found = 0;

                    if(!ridfile)
                    {
                        ridfile.close();
                        cout << "\nride file does not exist...";
                    }
                    else
                    {

                        string rid_regno;
                        string rid_route;

                        string bus_regno;
                        string bus_brand;
                        string bus_model;
                        string bus_color;
                        string bus_g_weight;
                        string bus_manu_date;
                        int bus_cost;
                        int bus_pes_cap;
                        string bus_eng;
                        string bus_eng_power;
                        string bus_f_type;
                        int bus_f_cap;
                        float bus_mileage;

                        string emp_regno;
                        string emp_fname;
                        string emp_lname;
                        string emp_age;
                        string emp_cnic;
                        string emp_phone;
                        string emp_address;
                        int emp_salary;
                        string emp_rankd;


                        int ridfound = 0;

                        ridfile >> rid_regno     >> rid_route
                                >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        while(!ridfile.eof())
                        {

                            if(tb_regno == bus_regno)
                            {
                                
                                cout << "\n\n\nRide Found!!!";

                                cout << "\n=====================================================================";
                                cout << "\nRide Number : " << rid_regno;
                                cout << "\nRoute : " << rid_route;
                                cout << "\n---------------------------------------------------------------------";
                                cout << "\nEmployee Registration Number: " << emp_regno
                                    << "\nFirst Name: " << emp_fname
                                    << "\nLast Name: " << emp_lname
                                    << "\nAge: " << emp_age
                                    << "\nCNIC: " << emp_cnic
                                    << "\nPhone Number: " << emp_phone
                                    << "\nAddress: " << emp_address
                                    << "\nDepartment: " << emp_rankd
                                    << "\nSalary: " << emp_salary ;
                                cout << "\n---------------------------------------------------------------------";
                                cout << "\nBus Registration Number: " << bus_regno
                                    << "\nBrand: " << bus_brand 
                                    << "\nModel: " << bus_model 
                                    << "\nColor: " << bus_color
                                    << "\nGross Weight: " << bus_g_weight
                                    << "\nManufacturing date: " << bus_manu_date
                                    << "\nCost: " << bus_cost
                                    << "\nPassenger Capacity: " << bus_pes_cap
                                    << "\nEngine Number: " << bus_eng 
                                    << "\nEngine Power: " << bus_eng_power
                                    << "\nFuel Type: " << bus_f_type 
                                    << "\nFuel Capacity" << bus_f_cap
                                    << "\nMilage(kml): " << bus_mileage ;
                                cout << "\n=====================================================================\n\n";

                                ridfound++;

                                ridfile.close();

                                cout << "\n\nDeleting Information!!!";


                                fstream tempfile;

                                tempfile.open("tempfile.txt", ios::out | ios::app);

                                ridfile.open("ridfile.txt", ios::in);
                                

                                ridfile >> rid_regno     >> rid_route
                                        >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                        >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                        >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                        >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                        >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                                while(!ridfile.eof())
                                {

                                    if(tb_regno != bus_regno)
                                    {
                                        tempfile << rid_regno     << " " << rid_route   << " "
                                                 << emp_regno     << " " << emp_fname   << " " << emp_lname   << " " << emp_age    << " " << emp_cnic      << " "
                                                 << emp_phone     << " " << emp_address << " " << emp_rankd   << " " << emp_salary << " "
                                                 << bus_regno     << " " << bus_brand   << " " << bus_model   << " " << bus_color  << " " << bus_g_weight  << " "
                                                 << bus_manu_date << " " << bus_cost    << " " << bus_pes_cap << " " << bus_eng    << " " << bus_eng_power << " "
                                                 << bus_f_type    << " " << bus_f_cap   << " " << bus_mileage << "\n" ;
                                    }

                                    ridfile >> rid_regno     >> rid_route
                                            >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                            >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                            >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                            >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                            >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                                }

                                ridfile.close();
                                tempfile.close();

                                remove("ridfile.txt");
                                rename("tempfile.txt", "ridfile.txt");

                                cout << "\n\nDeleted Successfully!!!";

                            }

                            ridfile >> rid_regno     >> rid_route
                                    >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                    >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                    >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                    >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                    >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        }

                        if(ridfound == 0)
                        {
                        cout << "\nride could not be found...\n";
                        }

                    }

                }


            }

            busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                    >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                    >> bus_f_type    >> bus_f_cap >> bus_mileage ;

        }

        if(found == 0)
        {
        cout << "\n\nBus could not be found!!!\n";
        }

    }

    cout << endl << endl << endl ;
    system("pause");

}



void Bus::bus_allinfo()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    cout << "\n\n\t\t\tBusses Information\n\n";


    int totalbus=0, totalcap=0 ;
    int totalcost=0 ;

    fstream busfile;

    busfile.open("busfile.txt", ios::in);

    if(!busfile)
    {
        busfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {

        busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                >> bus_f_type    >> bus_f_cap >> bus_mileage ;


        while(!busfile.eof())
        {

            totalbus++ ;

            totalcost += bus_cost ;

            totalcap += bus_pes_cap ;

            busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                    >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                    >> bus_f_type    >> bus_f_cap >> bus_mileage ;

        }

        busfile.close();

    }

    cout << "\n=============================================================";
    cout << "\nTotal Number of Buses : " << totalbus ;
    cout << "\n-------------------------------------------------------------";
    cout << "\nTotal Cost of Buses   : " << totalcost ;
    cout << "\n-------------------------------------------------------------";
    cout << "\nTotal Number of Seats : " << totalcap ;
    cout << "\n=============================================================\n\n";

    cout << endl << endl << endl ;
    system("pause");

}



void Ride::ride_add()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";


    fstream busfile, empfile, ridfile;

    busfile.open("busfile.txt", ios::in);
    empfile.open("empfile.txt", ios::in);
    ridfile.open("ridfile.txt", ios::in);
    
    if(!busfile)
    {
        cout << "\nBus File does not Exist!!!";
        busfile.close();
        empfile.close();
        ridfile.close();
    }
    else if(!empfile)
    {
        cout << "\nEmployee File does not Exist!!!";
        busfile.close();
        empfile.close();
        ridfile.close();
    }
    else if(!ridfile)
    {

        cout <<"\nRide File does not Exist!!!";
        cout <<"\n\nAdd New Ride\n";

        string tb_regno;
        cout << "\nEnter Bus Registration Number : ";
        cin >> tb_regno;

        busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                >> bus_f_type    >> bus_f_cap >> bus_mileage ;

        int busfound = 0;

        while(!busfile.eof())
        {
            if(bus_regno == tb_regno)
            {
                cout << "\nBus Found"
                     << "\nPassenger Capacity : " << bus_pes_cap ;
                busfound++;
                
                string te_regno;
                cout << "\n\nEnter Employee Registration Number : ";
                cin >> te_regno;

                empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                        >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

                int empfound = 0;

                while(!empfile.eof())
                {
                    if(emp_regno == te_regno)
                    {
                        cout << "\nEmployee Found";
                        empfound++;

                        if(emp_rankd != "Driver")
                        {
                            cout << "\nError...Employee is not a Driver";
                            cout << "\nEmployee is in " << emp_rankd << " department";
                            empfile.close();
                            busfile.close();
                            ridfile.close();
                        }
                        else
                        {
                            cout << "\n\n*************Ride Information**************"
                                 << "\nBus Registration Number    : " << bus_regno
                                 << "\nBus Capacity               : " << bus_pes_cap
                                 << "\nDriver Registration Number : " << emp_regno
                                 << "\nDriver Name                : " << emp_fname + " " + emp_lname
                                 << "\n*******************************************\n" ;

                            cout << "\nEnter Ride Number : ";
                            cin >> rid_regno;

                            route_show();

                            int rop;
                            rs:
                            cout << "\nSelect Route (1-5) : ";
                            cin >> rop;

                            switch(rop)
                            {
                                case 1:
                                {
                                    rid_route = r_1;
                                }break;
                                case 2:
                                {
                                    rid_route = r_2;
                                }break;
                                case 3:
                                {
                                    rid_route = r_3;
                                }break;
                                case 4:
                                {
                                    rid_route = r_4;
                                }break;
                                case 5:
                                {
                                    rid_route = r_5;
                                }break;
                                default:
                                {
                                    cout << "\nSelect the Correct Option!!";
                                    goto rs;
                                }
                            }

                            cout << "\nRoute Selected : " << rid_route ;

                            cout << "\n\n\nRIDE INFORMATION : ";
                            cout << "\n=====================================================================";
                            cout << "\nRide Number : " << rid_regno;
                            cout << "\nRoute : " << rid_route;
                            cout << "\n---------------------------------------------------------------------";
                            cout << "\nEmployee Registration Number: " << emp_regno
                                 << "\nFirst Name: " << emp_fname
                                 << "\nLast Name: " << emp_lname
                                 << "\nAge: " << emp_age
                                 << "\nCNIC: " << emp_cnic
                                 << "\nPhone Number: " << emp_phone
                                 << "\nAddress: " << emp_address
                                 << "\nDepartment: " << emp_rankd
                                 << "\nSalary: " << emp_salary ;
                            cout << "\n---------------------------------------------------------------------";
                            cout << "\nBus Registration Number: " << bus_regno
                                 << "\nBrand: " << bus_brand 
                                 << "\nModel: " << bus_model 
                                 << "\nColor: " << bus_color
                                 << "\nGross Weight: " << bus_g_weight
                                 << "\nManufacturing date: " << bus_manu_date
                                 << "\nCost: " << bus_cost
                                 << "\nPassenger Capacity: " << bus_pes_cap
                                 << "\nEngine Number: " << bus_eng 
                                 << "\nEngine Power: " << bus_eng_power
                                 << "\nFuel Type: " << bus_f_type 
                                 << "\nFuel Capacity" << bus_f_cap
                                 << "\nMilage(kml): " << bus_mileage ;
                            cout << "\n=====================================================================\n\n";

                            
                            ridfile.close();
                            ridfile.open("ridfile.txt", ios::out | ios::app);

                            ridfile << rid_regno     << " " << rid_route   << " "
                                    << emp_regno     << " " << emp_fname   << " " << emp_lname   << " " << emp_age    << " " << emp_cnic      << " "
                                    << emp_phone     << " " << emp_address << " " << emp_rankd   << " " << emp_salary << " "
                                    << bus_regno     << " " << bus_brand   << " " << bus_model   << " " << bus_color  << " " << bus_g_weight  << " "
                                    << bus_manu_date << " " << bus_cost    << " " << bus_pes_cap << " " << bus_eng    << " " << bus_eng_power << " "
                                    << bus_f_type    << " " << bus_f_cap   << " " << bus_mileage << "\n" ;
                            
                            ridfile.close();
                            empfile.close();
                            busfile.close();

                            cout << "\nRide Saved to File!!!";

                        }

                    }

                    empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                            >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

                }

                if(empfound == 0)
                {
                    cout << "\nEmployee could not be found!!!";
                    empfile.close();
                    busfile.close();
                    ridfile.close();
                }

            }

            busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                    >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                    >> bus_f_type    >> bus_f_cap >> bus_mileage ;

        }

        if(busfound == 0)
        {
            cout << "\nBus could not be found!!!";
            empfile.close();
            busfile.close();
            ridfile.close();
        }

    }
    else
    {


        ridfile >> rid_regno     >> rid_route
                >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

        string tridee_regno;
        cout << "\nEnter Ride Number : ";
        cin >> tridee_regno;

        int sameride = 0;

        while(!ridfile.eof())
        {

            if(tridee_regno == rid_regno)
            {
                cout << "\nSame Ride Number Already Exists!!!";
                sameride++;
                cout << "\n\nRIDE INFORMATION : ";
                cout << "\n=====================================================================";
                cout << "\nRide Number : " << rid_regno;
                cout << "\nRoute : " << rid_route;
                cout << "\n---------------------------------------------------------------------";
                cout << "\nEmployee Registration Number: " << emp_regno
                        << "\nFirst Name: " << emp_fname
                        << "\nLast Name: " << emp_lname
                        << "\nAge: " << emp_age
                        << "\nCNIC: " << emp_cnic
                        << "\nPhone Number: " << emp_phone
                        << "\nAddress: " << emp_address
                        << "\nDepartment: " << emp_rankd
                        << "\nSalary: " << emp_salary ;
                cout << "\n---------------------------------------------------------------------";
                cout << "\nBus Registration Number: " << bus_regno
                        << "\nBrand: " << bus_brand 
                        << "\nModel: " << bus_model 
                        << "\nColor: " << bus_color
                        << "\nGross Weight: " << bus_g_weight
                        << "\nManufacturing date: " << bus_manu_date
                        << "\nCost: " << bus_cost
                        << "\nPassenger Capacity: " << bus_pes_cap
                        << "\nEngine Number: " << bus_eng 
                        << "\nEngine Power: " << bus_eng_power
                        << "\nFuel Type: " << bus_f_type 
                        << "\nFuel Capacity" << bus_f_cap
                        << "\nMilage(kml): " << bus_mileage ;
                cout << "\n=====================================================================\n\n";
            }

            ridfile >> rid_regno     >> rid_route
                    >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                    >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                    >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                    >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                    >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

        }

        if(sameride != 0)
        {
            cout << "\nExiting\n";
            ridfile.close();
            busfile.close();
            empfile.close();
        }
        else
        {

            string te_regno;
            cout << "\nEnter Employee Registration Number : ";
            cin >> te_regno;

            int empfound = 0;

            empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                    >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

            while(!empfile.eof())
            {
                if(emp_regno == te_regno)
                {
                    empfound++;
                }
                empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                        >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;
            }

            if(empfound == 0)
            {
                cout << "\nEmployee does not Exist!!";
                ridfile.close();
                empfile.close();
                busfile.close();
            }
            else
            {

                int empfree = 0;

                ridfile >> rid_regno     >> rid_route
                        >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                        >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                        >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                        >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                        >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                while(!ridfile.eof())
                {
                    if(te_regno == emp_regno)
                    {
                        cout << "\nEmployee is Already Driving a Bus!!!";
                        cout << "\nRide Number : " << rid_regno 
                             << "\nRoute : " << rid_route 
                             << "\nBus Registration Number : " << bus_regno ;
                        empfree++;
                    }
                    ridfile >> rid_regno     >> rid_route
                            >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                            >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                            >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                            >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                            >> bus_f_type    >> bus_f_cap   >> bus_mileage ;
                }

                if(empfree != 0)
                {
                    cout << "\nExiting";
                    ridfile.close();
                    empfile.close();
                    busfile.close();
                }
                else
                {

                    string tbus_regno;
                    cout << "\nEnter Bus Registration Number : ";
                    cin >> tbus_regno;

                    int busexist = 0;

                    busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                            >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                            >> bus_f_type    >> bus_f_cap >> bus_mileage ;

                    while(!busfile.eof())
                    {
                        if(tbus_regno == bus_regno)
                        {
                            busexist++;
                        }

                        busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                                >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                                >> bus_f_type    >> bus_f_cap >> bus_mileage ;
                    }


                    if(busexist == 0)
                    {
                        cout << "\nBus does not exist!!";
                        ridfile.close();
                        empfile.close();
                        busfile.close();
                    }
                    else
                    {

                        int busfreee = 0;

                        ridfile >> rid_regno     >> rid_route
                                >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                        while(!ridfile.eof())
                        {
                            if(tbus_regno == bus_regno)
                            {
                                cout << "\nBus is Already on a Ride!!!";
                                cout << "\nRide Number : " << rid_regno 
                                     << "\nRoute : " << rid_route 
                                     << "\nBus Registration Number : " << bus_regno ;
                                busfreee++;
                            }
                            ridfile >> rid_regno     >> rid_route
                                    >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                                    >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                                    >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                                    >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                                    >> bus_f_type    >> bus_f_cap   >> bus_mileage ;
                        }

                        if(busfreee != 0)
                        {
                            cout << "\nExiting";
                            ridfile.close();
                            empfile.close();
                            busfile.close();
                        }
                        else
                        {

                            route_show();

                            int rope;
                            rsp:
                            cout << "\nSelect Route (1-5) : ";
                            cin >> rope;

                            switch(rope)
                            {
                                case 1:
                                {
                                    rid_route = r_1;
                                }break;
                                case 2:
                                {
                                    rid_route = r_2;
                                }break;
                                case 3:
                                {
                                    rid_route = r_3;
                                }break;
                                case 4:
                                {
                                    rid_route = r_4;
                                }break;
                                case 5:
                                {
                                    rid_route = r_5;
                                }break;
                                default:
                                {
                                    cout << "\nSelect the Correct Option!!";
                                    goto rsp;
                                }
                            }

                            cout << "\nRoute Selected    : " << rid_route ;
                            cout << "\nBus Selected      : " << tbus_regno ;
                            cout << "\nEmployee Selected : " << te_regno ;
                            cout << "\nRide Number       : " << tridee_regno ;


                            empfile.close();
                            busfile.close();
                            ridfile.close();

                            empfile.open("empfile.txt", ios::in);
                            busfile.open("busfile.txt", ios::in);


                            busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                                    >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                                    >> bus_f_type    >> bus_f_cap >> bus_mileage ;

                            while(!busfile.eof())
                            {

                                if(bus_regno == tbus_regno)
                                {

                                    empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                                            >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;

                                    while(!empfile.eof())
                                    {

                                        if(emp_regno == te_regno)
                                        {
                                            
                                            cout << "\n\n\nRIDE INFORMATION : ";
                                            cout << "\n=====================================================================";
                                            cout << "\nRide Number : " << tridee_regno;
                                            cout << "\nRoute : " << rid_route;
                                            cout << "\n---------------------------------------------------------------------";
                                            cout << "\nEmployee Registration Number: " << emp_regno
                                                << "\nFirst Name: " << emp_fname
                                                << "\nLast Name: " << emp_lname
                                                << "\nAge: " << emp_age
                                                << "\nCNIC: " << emp_cnic
                                                << "\nPhone Number: " << emp_phone
                                                << "\nAddress: " << emp_address
                                                << "\nDepartment: " << emp_rankd
                                                << "\nSalary: " << emp_salary ;
                                            cout << "\n---------------------------------------------------------------------";
                                            cout << "\nBus Registration Number: " << bus_regno
                                                << "\nBrand: " << bus_brand 
                                                << "\nModel: " << bus_model 
                                                << "\nColor: " << bus_color
                                                << "\nGross Weight: " << bus_g_weight
                                                << "\nManufacturing date: " << bus_manu_date
                                                << "\nCost: " << bus_cost
                                                << "\nPassenger Capacity: " << bus_pes_cap
                                                << "\nEngine Number: " << bus_eng 
                                                << "\nEngine Power: " << bus_eng_power
                                                << "\nFuel Type: " << bus_f_type 
                                                << "\nFuel Capacity" << bus_f_cap
                                                << "\nMilage(kml): " << bus_mileage ;
                                            cout << "\n=====================================================================\n\n";

                                            
                                            ridfile.open("ridfile.txt", ios::out | ios::app);

                                            ridfile << tridee_regno     << " " << rid_route   << " "
                                                    << emp_regno        << " " << emp_fname   << " " << emp_lname   << " " << emp_age    << " " << emp_cnic      << " "
                                                    << emp_phone        << " " << emp_address << " " << emp_rankd   << " " << emp_salary << " "
                                                    << bus_regno        << " " << bus_brand   << " " << bus_model   << " " << bus_color  << " " << bus_g_weight  << " "
                                                    << bus_manu_date    << " " << bus_cost    << " " << bus_pes_cap << " " << bus_eng    << " " << bus_eng_power << " "
                                                    << bus_f_type       << " " << bus_f_cap   << " " << bus_mileage << "\n" ;
                                            
                                            ridfile.close();
                                            empfile.close();
                                            busfile.close();

                                            cout << "\nRide Saved to File!!!";

                                        }

                                        empfile >> emp_regno >> emp_fname >> emp_lname >> emp_age >> emp_cnic
                                                >> emp_phone >> emp_address >> emp_rankd >> emp_salary ;
                                    }

                                }

                                busfile >> bus_regno     >> bus_brand >> bus_model   >> bus_color >> bus_g_weight  
                                        >> bus_manu_date >> bus_cost  >> bus_pes_cap >> bus_eng   >> bus_eng_power 
                                        >> bus_f_type    >> bus_f_cap >> bus_mileage ;
                            }

                        }

                    }

                }
                
            }

        }

    }
    
    cout << endl << endl << endl ;
    system("pause");

}



void Ride::ride_showall()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream ridfile;

    ridfile.open("ridfile.txt", ios::in);

    if(!ridfile)
    {
        cout << "\nFile does not Exist!!!";
        ridfile.close();
    }
    else
    {

        ridfile >> rid_regno     >> rid_route
                >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

        cout << "\n\t\t\tAll Rides\n";

        cout << "\n\nRIDE INFORMATION : \n";

        while(!ridfile.eof())
        {

            cout << "\n=====================================================================";
            cout << "\nRide Number : " << rid_regno;
            cout << "\nRoute : " << rid_route;
            cout << "\n---------------------------------------------------------------------";
            cout << "\nEmployee Registration Number: " << emp_regno
                << "\nFirst Name: " << emp_fname
                << "\nLast Name: " << emp_lname
                << "\nAge: " << emp_age
                << "\nCNIC: " << emp_cnic
                << "\nPhone Number: " << emp_phone
                << "\nAddress: " << emp_address
                << "\nDepartment: " << emp_rankd
                << "\nSalary: " << emp_salary ;
            cout << "\n---------------------------------------------------------------------";
            cout << "\nBus Registration Number: " << bus_regno
                << "\nBrand: " << bus_brand 
                << "\nModel: " << bus_model 
                << "\nColor: " << bus_color
                << "\nGross Weight: " << bus_g_weight
                << "\nManufacturing date: " << bus_manu_date
                << "\nCost: " << bus_cost
                << "\nPassenger Capacity: " << bus_pes_cap
                << "\nEngine Number: " << bus_eng 
                << "\nEngine Power: " << bus_eng_power
                << "\nFuel Type: " << bus_f_type 
                << "\nFuel Capacity" << bus_f_cap
                << "\nMilage(kml): " << bus_mileage ;
            cout << "\n=====================================================================\n\n";

            ridfile >> rid_regno     >> rid_route
                    >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                    >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                    >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                    >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                    >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

        }

        ridfile.close();

    }

    cout << endl << endl << endl ;
    system("pause");

}



void Ride::ride_delete()
{

    system("cls");

    cout << "\n\n\n\t\t\t******* ================= *******\n" 
         <<       "\t\t\t******* IMTravels Systems *******\n"
         <<       "\t\t\t******* ================= *******\n\n\n";

    fstream ridfile;

    ridfile.open("ridfile.txt", ios::in);

    int found = 0;

    if(!ridfile)
    {
        ridfile.close();
        cout << "\nFile does not Exist!!!";
    }
    else
    {

        string tr_reg, del_reg;

        int ridfound = 0;

        ridfile >> rid_regno     >> rid_route
                >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                >> bus_f_type    >> bus_f_cap   >> bus_mileage ;


        cout << "\nEnter Ride Number : ";
        cin >> tr_reg;

        del_reg = tr_reg;

        while(!ridfile.eof())
        {

            if(rid_regno == tr_reg)
            {
                
                cout << "\n\n\nRide Found!!!";

                cout << "\n=====================================================================";
                cout << "\nRide Number : " << rid_regno;
                cout << "\nRoute : " << rid_route;
                cout << "\n---------------------------------------------------------------------";
                cout << "\nEmployee Registration Number: " << emp_regno
                    << "\nFirst Name: " << emp_fname
                    << "\nLast Name: " << emp_lname
                    << "\nAge: " << emp_age
                    << "\nCNIC: " << emp_cnic
                    << "\nPhone Number: " << emp_phone
                    << "\nAddress: " << emp_address
                    << "\nDepartment: " << emp_rankd
                    << "\nSalary: " << emp_salary ;
                cout << "\n---------------------------------------------------------------------";
                cout << "\nBus Registration Number: " << bus_regno
                    << "\nBrand: " << bus_brand 
                    << "\nModel: " << bus_model 
                    << "\nColor: " << bus_color
                    << "\nGross Weight: " << bus_g_weight
                    << "\nManufacturing date: " << bus_manu_date
                    << "\nCost: " << bus_cost
                    << "\nPassenger Capacity: " << bus_pes_cap
                    << "\nEngine Number: " << bus_eng 
                    << "\nEngine Power: " << bus_eng_power
                    << "\nFuel Type: " << bus_f_type 
                    << "\nFuel Capacity" << bus_f_cap
                    << "\nMilage(kml): " << bus_mileage ;
                cout << "\n=====================================================================\n\n";

                ridfound++;

                ridfile.close();

                cout << "\n\nDeleting Information!!!";


                fstream tempfile;

                tempfile.open("tempfile.txt", ios::out | ios::app);

                ridfile.open("ridfile.txt", ios::in);
                

                ridfile >> rid_regno     >> rid_route
                        >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                        >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                        >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                        >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                        >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                while(!ridfile.eof())
                {

                    if(rid_regno != del_reg)
                    {
                        tempfile << rid_regno     << " " << rid_route   << " "
                                 << emp_regno     << " " << emp_fname   << " " << emp_lname   << " " << emp_age    << " " << emp_cnic      << " "
                                 << emp_phone     << " " << emp_address << " " << emp_rankd   << " " << emp_salary << " "
                                 << bus_regno     << " " << bus_brand   << " " << bus_model   << " " << bus_color  << " " << bus_g_weight  << " "
                                 << bus_manu_date << " " << bus_cost    << " " << bus_pes_cap << " " << bus_eng    << " " << bus_eng_power << " "
                                 << bus_f_type    << " " << bus_f_cap   << " " << bus_mileage << "\n" ;
                    }

                    ridfile >> rid_regno     >> rid_route
                            >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                            >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                            >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                            >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                            >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

                }

                ridfile.close();
                tempfile.close();

                remove("ridfile.txt");
                rename("tempfile.txt", "ridfile.txt");

                cout << "\n\nDeleted Successfully!!!";

            }

            ridfile >> rid_regno     >> rid_route
                    >> emp_regno     >> emp_fname   >> emp_lname   >> emp_age    >> emp_cnic
                    >> emp_phone     >> emp_address >> emp_rankd   >> emp_salary
                    >> bus_regno     >> bus_brand   >> bus_model   >> bus_color  >> bus_g_weight
                    >> bus_manu_date >> bus_cost    >> bus_pes_cap >> bus_eng    >> bus_eng_power
                    >> bus_f_type    >> bus_f_cap   >> bus_mileage ;

        }

        if(ridfound == 0)
        {
        cout << "\n\nRide could not be found!!!\n";
        }

    }

    cout << endl << endl << endl ;
    system("pause");

}



void IMTravels::mainmenu()
{

    int flag = 1;

    while(flag == 1)
    {

        system("cls");

        
        cout<< "\n\n================================================================================================================="
            <<   "\n------------------------------------------------IMTravels System-------------------------------------------------"
            <<   "\n-----------------------------------------------------------------------------------------------------------------"
            <<   "\n    1. Employee Tools           2. Bus Tools                          3. Ride Tools           4. Route Tools     "
            <<   "\n-----------------------------------------------------------------------------------------------------------------"
            <<   "\n    1. Add                      1. Add                                1. Add                  1. Show            "
            <<   "\n    2. Show all                 2. Show all                           2. Show all                                "
            <<   "\n    3. Search                   3. Search                             3. Delete                                  "
            <<   "\n    4. Update                   4. Update                                                                        "
            <<   "\n    5. Delete                   5. Delete                                                                        "
            <<   "\n    6. Overall Information      6. Overall Information                                        55. Exit Program   "
            <<   "\n-----------------------------------------------------------------------------------------------------------------"
            <<   "\n                                                                                                                 "
            <<   "\n                                               How to use main menu                                              "
            <<   "\n                                         step 1 : Select the desired tool                                        "
            <<   "\n                                        step 2 : Select the desired action                                       "
            <<   "\n                                               step 3 : Press Enter                                              "
            <<   "\n                                                     Examples                                                    "
            <<   "\n                                               for Add Employee : 11                                             "
            <<   "\n                                                for Search Bus : 23                                              "
            <<   "\n                                              for Show all Rides : 32                                            "
            <<   "\n                                                                                                                 "
            <<   "\n-----------------------------------------------------------------------------------------------------------------" ;
        cout<< "\n\n=================================================================================================================" ;


            
        m_start:

        cout << "\n\n Enter Your Choice : " ;

        int m_choice = 0;

        cin>>m_choice;

        switch(m_choice)
        {
            case 11:
            {
                emp_add();
            }break;
            case 12:
            {
                emp_showall();
            }break;
            case 13:
            {
                emp_search();
            }break;
            case 14:
            {
                emp_update();
            }break;
            case 15:
            {
                emp_delete();
            }break;
            case 16:
            {
                emp_allinfo();
            }break;
            case 21:
            {
                bus_add();
            }break;
            case 22:
            {
                bus_showall();
            }break;
            case 23:
            {
                bus_search();
            }break;
            case 24:
            {
                bus_update();
            }break;
            case 25:
            {
                bus_delete();
            }break;
            case 26:
            {
                bus_allinfo();
            }break;
            case 31:
            {
                ride_add();
            }break;
            case 32:
            {
                ride_showall();
            }break;
            case 33:
            {
                ride_delete();
            }break;
            case 41:
            {
                route_show_menu();
            }break;
            case 55:
            {
                flag = 0;
                exit(0);
            }break;
            default:
            {
            cout <<"\n Wrong Choice... Please Try Again...";
            goto m_start;
            }
        }
    }
}



//ADD HELLO WORLD FOR ISPECIAL PURSUN !!



int main()
{

    IMTravels a;

    system("cls");

    cout << "\n\n\t\t\t*************************";
    cout << "\n\t\t\tAuthentication Required!!";
    cout << "\n\t\t\t*************************";
    
    string username, password;

    cout << "\n\n Enter username : ";

    cin >> username;

    if(username == "admin")
    {
        cout << "\n\n Enter password : ";
        
        char al;

        for(int i = 0; i < 10; i++)
        {
            al = getch();
            password += al;
            cout << "*";
        }
        
        if(password == "helloworld")
        {
            cout << "\n\n";
            for(int o = 0; o < 30; o++)
            {
                cout << ".";
                cout << " ";
                Sleep(1);
            }
            {
                //helloworlddisplay
                cout << endl << endl << endl;

                {

                    cout << " H";
                    Sleep(500);
                    cout << "E";
                    Sleep(400);
                    cout << "L";
                    Sleep(300);
                    cout << "L";
                    Sleep(200);
                    cout << "O";
                    Sleep(100);
                    cout << " ";
                    Sleep(50);
                    cout << "W";
                    Sleep(50);
                    cout << "O";
                    Sleep(50);
                    cout << "R";
                    Sleep(200);
                    cout << "L";
                    Sleep(50);
                    cout << "D";
                    Sleep(200);
                    cout << "!";
                    Sleep(400);

                    cout << endl << endl ;

                    system("pause");
                }

            }

            a.mainmenu();
        }
        else
        cout << "Wrong Password !!!";
    }
    else
    cout << "Wrong User !!!";

    return 0;

}


//username : admin
//password : helloworld
