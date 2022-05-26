#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <regex>

using namespace std;

long accno = 1400000751;

class bank
{
    long ano;
    char cname[30];
    char fname[30];
    char mname[30];
    long long mobno;
    char email[30];
    char address[100];
    long long aadhar;
    long long creditCardNum;
    char dofo[10];
    char dofb[10];
    char type[10];
    float deposit;

public:
    // longest bitonic subsequence
    int LongestBitonicSequence(vector<int> nums)
    {
        int dp[nums.size()];
        dp[0] = 1;
        // return dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int dp2[nums.size()];
        reverse(nums.begin(), nums.end());
        dp2[0] = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            dp2[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        int large = -9999;
        reverse(dp, dp + nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            large = max(dp[i] + dp2[i] - 1, large);
        } // cout<<dp[i]<<" "<<dp2[i]<<endl;

        return large;
    }

    void bitonicmain()
    {
        vector<int> arr[20];
        int lar = 0;
        int bitonic[20];
        int largest = -9999;

        string names[20] = {"Ayush", "Mudit", "Siddharth", "Drishika",
                            "Shraddha", "Manu", "Neta Neta", "Dixit", "bansal", "Modi",
                            "Jain", "Kaushik", "Chauhan", "Garg", "Singhai", "Pathak",
                            "Narang", "Saxena", "Krishna", "Gupta"};

        // accesing data from file activity.txt

        int row = 20;
        int col = 10;
        ifstream inputfile("activity.txt");
        if (!inputfile.is_open())
            cout << "Error opening file";
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                int z;
                inputfile >> z;
                arr[r].push_back(z);
            }
        }
        for (int i = 0; i < 20; i++)
        {
            int temp = LongestBitonicSequence(arr[i]);
            bitonic[i] = temp * 10 + i;
            // bitonic[i][1]=i;
        }
        sort(bitonic, bitonic + 20);
        int order[20];
        for (int i = 0; i < 20; i++)
        {
            // order[i]=bitonic[i]/10;
            order[i] = bitonic[i] % 10;
        }
        // sort(bitonic,bitonic+20);
        cout << "\t\t\t\tTHE ORDER IN WHICH WE SHOULD APPROACH IS ::" << endl;
        for (int i = 0; i < 20; i++)
            cout << "\t\t\t\t\t\t" << names[i] << endl;
        sleep(5);
    }

    // Function to return max value that can be put in knapsack of capacity W.
    void knapSack(int W, int wt[], int val[], int n)
    {
        int **dp = new int *[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[W + 1];
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= W; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
        }
        cout << "\n\t\t\t\t||________________________________________________________________||\n";
        cout << "\t\t\t\t\t  THE LARGEST YOU CAN GET IS :: " << dp[n][W] << endl;
        cout << "\t\t\t\t\t  AND THE VALUES USED ARE -> " << endl;
        int res = dp[n][W];
        int i, w;
        w = W;
        for (i = n; i > 0 && res > 0; i--)
        {

            // either the result comes from the top
            // (K[i-1][w]) or from (val[i-1] + K[i-1]
            // [w-wt[i-1]]) as in Knapsack table. If
            // it comes from the latter one/ it means
            // the item is included.
            if (res == dp[i - 1][w])
                continue;
            else
            {

                // This item is included.
                cout << "\t\t\t\t\t  Amount :: " << wt[i - 1] << " Interest :: " << val[i - 1] << endl;

                // Since this weight is included its
                // value is deducted
                res = res - val[i - 1];
                w = w - wt[i - 1];
            }
        }
    }

    void knapmain()
    {
        int n;
        system("cls");
        cout << "\n\n\n\n\t\t\t\t||****************************************************************||\n";
        cout << "\t\t\t\t||================================================================||";
        cout << "\n\t\t\t\t||________________________________________________________________||\n";
        cout << "\t\t\t\t\t  ENTER NUMBER OF PEOPLE \t:: ";
        cin >> n;
        int sum = 7000000;
        int principle[n];
        int interest[n];
        int time[n];
        int returnOfIn[n];
        for (int i = 0; i < n; i++)
        {
            cout << "\t\t\t\t\t  FOR PERSON " << (i + 1) << endl;
            cout << "\t\t\t\t\t  ENTER THE AMOUNT OF LOAN \t:: ";
            cin >> principle[i];
            cout << "\t\t\t\t\t  ENTER INTEREST \t\t:: ";
            cin >> interest[i];
            cout << "\t\t\t\t\t  ENTER TIME \t\t\t:: ";
            cin >> time[i];
        }
        for (int i = 0; i < n; i++)
        {
            returnOfIn[i] = (int)(principle[i] * interest[i] * time[i]) / 100;
        }
        knapSack(sum, principle, returnOfIn, n);
        // cout << "The max we can get out of these are: " << largest;
        sleep(5);
    }

    int minCoins(int V)
    {
        // table[i] will be storing the minimum number of coins
        // required for i value.  So table[V] will have result
        int coins[] = {2000, 1000, 500, 200, 100, 50, 20, 10};
        int table[V + 1];
        int m = 8;
        // Base case (If given value V is 0)
        table[0] = 0;

        // Initialize all table values as Infinite
        for (int i = 1; i <= V; i++)
            table[i] = INT_MAX;

        // Compute minimum coins required for all
        // values from 1 to V
        for (int i = 1; i <= V; i++)
        {
            // Go through all coins smaller than i
            for (int j = 0; j < m; j++)
                if (coins[j] <= i)
                {
                    int sub_res = table[i - coins[j]];
                    if (sub_res != INT_MAX && sub_res + 1 < table[i])
                        table[i] = sub_res + 1;
                }
        }

        if (table[V] == INT_MAX)
            return -1;

        return table[V];
    }

    // For credit card validation
    bool LuhnAlgorithm(string cardNum)
    {
        int numDigits = cardNum.length();
        bool secondDigit = false;
        int digit, totalSum = 0;

        if (numDigits == 12)
        {
            for (int i = numDigits - 1; i >= 0; i--)
            {
                digit = cardNum[i] - '0';

                if (secondDigit == true)
                {
                    digit *= 2;
                }
                cout << digit << endl;

                totalSum += (digit / 10);
                totalSum += (digit % 10);
                // cout << totalSum << endl;

                secondDigit = !secondDigit;
            }
        }
        else
        {
            return false;
        }

        if (totalSum % 10 == 0)
        {
            return true;
        }
        return false;
    }

    bool isValidAadhaarNumber(long long adhar)
    {

        // Regex to check valid Aadhaar number.
        string str = to_string(adhar);
        const regex pattern("^[2-9]{1}[0-9]{11}$");

        // If the Aadhaar number
        // is empty return false
        if (str.empty())
        {
            return false;
        }

        // Return true if the Aadhaar number
        // matched the ReGex
        if (regex_match(str, pattern))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isValidPhoneNumber(long long no)
    {

        // Regex to check valid Aadhaar number.
        string str = to_string(no);
        const regex pattern("^[1-9]{1}[0-9]{9}$");

        // If the Aadhaar number
        // is empty return false
        if (str.empty())
        {
            return false;
        }

        // Return true if the Aadhaar number
        // matched the ReGex
        if (regex_match(str, pattern))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    long long creditCardGenerator()
    {
        srand(time(0));
        long long cardNum = 0;
        for (int i = 0; i < 12; i++)
        {
            cardNum = cardNum * 10 + (rand() % 10);
            cout << "\t\t\t\t Your Credit card number: " << creditCardNum << endl;
        }

        return cardNum;
    }

    void getdata()
    {
        cout << endl;
        system("cls");
        ano = accno;
        cout << "\n\n\n\n\t\t\t\t||****************************************************************||\n";
        cout << "\t\t\t\t||     ******** ENTER THE DETAILS OF ACCOUNT HOLDER ********      ||\n";
        cout << "\t\t\t\t||================================================================||";
        cout << "\n\t\t\t\t||________________________________________________________________||\n";
        cout << "\n\n\t\t\t\t    ENTER NAME OF ACCOUNT HOLDER \t:: ";
        cin.ignore();
        gets(cname);
        cout << "\t\t\t\t    ENTER FATHER's NAME \t\t:: ";
        gets(fname);
        cout << "\t\t\t\t    ENTER MOTHER's NAME \t\t:: ";
        gets(mname);
        cout << "\t\t\t\t    ENTER THE CONTACT NUMBER \t\t:: ";
        cin >> mobno;
        while (!isValidPhoneNumber(mobno))
        {
            cout << "\t\t\t\t    ENTER VALID PHONE NUMBER \t\t:: ";
            cin >> mobno;
        }
        cin.ignore();
        cout << "\t\t\t\t    ENTER THE EMAIL ADDRESS \t\t:: ";
        cin >> email;
        cout << "\t\t\t\t    ENTER THE RESIDENTIAL ADDRESS \t:: ";
        cin.ignore();
        gets(address);
        cout << "\t\t\t\t    ENTER THE AADHAR NUMBER \t\t:: ";
        cin >> aadhar;
        while (!isValidAadhaarNumber(aadhar))
        {
            cout << "\t\t\t\t    ENTER VALID AADHAR NUMBER \t\t:: ";
            cin >> aadhar;
        }
        cout << "\t\t\t\t    ENTER THE DATE OF ACCOUNT OPENING\t:: ";
        cin.ignore();
        gets(dofo);
        cout << "\t\t\t\t    ACCOUNT TYPES\n\t\t\t\t \t\t 1. SAVINGS \n\t\t\t\t \t\t 2. SALARY \t\t\n";
        cout << "\t\t\t\t    ENTER THE ACCOUNT TYPE (1/2) \t:: ";
        int t;
        cin >> t;
        if (t == 1)
            strcpy(type, "SAVINGS");
        else if (t == 2)
            strcpy(type, "SALARY");
        cout << "\t\t\t\t    ENTER THE DEPOSIT AMOUNT \t\t:: ";
        cin >> deposit;
        cout << "\t\t\t\t    DO YOU HAVE A CREDIT CARD?\n\t\t\t\t \t\t 1.YES \n\t\t\t\t \t\t 2.NO \t\t\n";
        cout << "\t\t\t\t    ENTER YOUR CHOICE (1/2) \t:: ";
        cin >> t;

        char ch;
        if (t == 1)
        {
            cout << "\n\t\t\t\t    To validate your credit card number, enter [Y/y]: ";
            cin >> ch;

            if (ch == 'Y' || ch == 'y')
            {
                string cardNum;
                cout << "\n\t\t\t\t    Enter your credit card number for validation: ";
                cin >> cardNum;
                LuhnAlgorithm(cardNum);
            }
        }

        else if (t == 2)
        {
            cout << "\t\t\t\t Do you want a credit card? [Y/N]: ";
            cin >> ch;

            if (ch == 'Y' || ch == 'y')
            {
                creditCardNum = creditCardGenerator();
            }
        }

        else
        {
            cout << "\t\t\t\t    INVALID INPUT!!!" << endl;
        }

        cout << "\n\n\t\t\t\t====================================================================";
        accno++;
    }

    void putdata()
    {
        cout << endl;
        cout << "\n\n\n\n\t\t\t\t||****************************************************************||\n";
        cout << "\t\t\t\t||          ********** DATA OF ACCOUNT HOLDER **********          ||\n";
        cout << "\t\t\t\t||================================================================||";
        cout << "\n\t\t\t\t||________________________________________________________________||\n";
        cout << "\n\t\t\t\t\tACCOUNT NUMBER \t\t:: ";
        cout << ano;
        cout << "\n\t\t\t\t\tNAME OF ACCOUNT HOLDER \t:: ";
        cout << cname;
        cout << "\n\t\t\t\t\tFATHER's NAME \t\t:: ";
        cout << fname;
        cout << "\n\t\t\t\t\tMOTHER's NAME \t\t:: ";
        cout << mname;
        cout << "\n\t\t\t\t\tCONTACT NUMBER \t\t:: ";
        cout << mobno;
        cout << "\n\t\t\t\t\tEMAIL ADDRESS \t\t:: ";
        cout << email;
        cout << "\n\t\t\t\t\tRESIDENTIAL ADDRESS \t:: ";
        cout << address;
        cout << "\n\t\t\t\t\tAADHAR NUMBER \t\t:: ";
        cout << aadhar;
        cout << "\n\t\t\t\t\tDATE OF ACCOUNT OPENING\t:: ";
        printf("%s", dofo);
        cout << "\n\t\t\t\t\tACCOUTN TYPE \t\t:: ";
        cout << type;
        cout << "\n\t\t\t\t\tAMOUNT \t\t\t:: ";
        cout << deposit;
    }

    void modify()
    {
        system("cls");
        cout << "\n\n\t\t\t\t    ENTER NEW NAME OF ACCOUNT HOLDER \t:: ";
        cin.ignore();
        gets(cname);
        cout << "\t\t\t\t    ENTER FATHER's NAME \t\t:: ";
        gets(fname);
        cout << "\t\t\t\t    ENTER MOTHER's NAME \t\t:: ";
        gets(mname);
        cout << "\t\t\t\t    ENTER THE NEW CONTACT NUMBER \t:: ";
        cin >> mobno;
        cin.ignore();
        cout << "\t\t\t\t    ENTER THE NEW EMAIL ADDRESS \t:: ";
        cin >> email;
        cout << "\t\t\t\t    ENTER THE NEW DEPOSIT AMOUNT \t:: ";
        cin >> deposit;
    }

    void withdraw()
    {
        long debit;
        long temp = deposit;
        system("cls");
        cout << "\n\n\t\t\t\t          ENTER AMOUNT TO BE WITHRAWN \t:: ";
        cin.ignore();
        cin >> debit;
        deposit = deposit - debit;
        if (deposit > 100)
        {

            cout << "\t\t\t\tTHE MINIMUM NUMBER OF DENOMINATION REQUIRED ARE: " << minCoins(debit)<<endl;
        }
        else
        {
            cout << "\t\t\t\t       ********   TRANSACTION NOT POSSIBLE   ******** \n ";
            deposit = temp;
        }
        cout << "\t\t\t\t\t        THE DEPOSIT AMOUNT \t:: ";
        cout << deposit;
    }

    int retano()
    {
        return ano;
    }

    char *retname()
    {
        return cname;
    }

    float retdeposit()
    {
        return deposit;
    }
};

void add()
{
    ofstream out("bank.txt", ios::app);
    bank s;
    s.getdata();
    out.write((char *)&s, sizeof(s));
    out.close();
    cout << "\n\t\t\t\t   ******** CUSTOMER DATA APPENDED TO THE FILE DATABASE ********\n";
}

void show()
{
    ifstream in("bank.txt", ios::in);
    bank s;
    int found = 0;
    while (in)
    {
        in.read((char *)&s, sizeof(s));
        if (in.eof())
            break;
        s.putdata();
        found = 1;
    }
    if (found == 0)
        cout << "\n\t\t\t\t     \t     ******** ACCOUNT NUMBER NOT FOUND ********\n";
    in.close();
}

void searchano()
{
    ifstream in("bank.txt", ios::in);
    int r;
    cout << "\n\n\n\n\t\t\t\t||****************************************************************||\n";
    cout << "\t\t\t\t||         **********   SEARCHING ACCOUNT INFO  **********        ||\n";
    cout << "\t\t\t\t||================================================================||";
    cout << "\n\t\t\t\t||________________________________________________________________||\n";
    cout << "\n\n\t\t\t\t          ENTER THE ACCOUNT NUMBER TO BE SEARCHED :: ";
    cin >> r;
    int found = 0;
    bank s;
    while (in)
    {
        in.read((char *)&s, sizeof(s));
        if (in.eof())
            break;
        if (s.retano() == r)
        {
            system("cls");
            s.putdata();
            cout << "\n\n\t\t\t        ||****************************************************************||\n";
            cout << "\n\t\t\t\t   ********  CUSTOMER DATA FOUND IN THE FILE DATABASE   ********\n";
            found = 1;
            break;
        }
    } // while ends
    if (found == 0)
        cout << "\n\t\t\t\t     \t     ******** ACCOUNT NUMBER NOT FOUND ********\n";
    in.close();
}

void searchname()
{
    ifstream in("bank.txt", ios::in);
    char n[30];
    cout << "\n\n\n\n\t\t\t\t||****************************************************************||\n";
    cout << "\t\t\t\t||         **********   SEARCHING ACCOUNT INFO  **********        ||\n";
    cout << "\t\t\t\t||================================================================||";
    cout << "\n\t\t\t\t||________________________________________________________________||\n";
    cout << "\n\n\t\t\t\t          ENTER THE CLIENT NAME TO BE SEARCHED :: ";
    cin.ignore();
    gets(n);
    int found = 0;
    bank s;
    while (in)
    {
        in.read((char *)&s, sizeof(s));
        if (in.eof())
            break;
        if (strcmpi(s.retname(), n) == 0)
        {
            s.putdata();
            found = 1;
        }
    } // while ends
    if (found == 0)
        cout << "\n\t\t\t\t     \t******** NO ACCOUNT HOLDER WITH GIVEN NAME ********\n";
    in.close();
}

void modify()
{
    ifstream in("bank.txt", ios::in);
    ofstream out("temp.txt", ios::out);
    int r;
    cout << "\n\n\n\n\t\t\t\t||****************************************************************||\n";
    cout << "\t\t\t\t||         **********   MODIFYING AN ACCOUNT   **********         ||\n";
    cout << "\t\t\t\t||================================================================||";
    cout << "\n\t\t\t\t||________________________________________________________________||\n";
    cout << "\n\n\t\t\t\t          ENTER THE ACCOUNT NUMBER TO BE MODIFIED :: ";
    cin >> r;
    int found = 0;
    bank s;
    while (in)
    {
        in.read((char *)&s, sizeof(s));
        if (in.eof())
            break;
        if (s.retano() == r)
        {
            s.modify();
            out.write((char *)&s, sizeof(s));
            cout << "\n\n\t\t\t     ||****************************************************************||\n";
            cout << "\n\t\t\t\t******** CUSTOMER DATA MODIFIED IN THE FILE DATABASE ********\n";
            found = 1;
        }
        else
            out.write((char *)&s, sizeof(s));
    } // while ends
    if (found == 0)
        cout << "\n\t\t\t\t     \t     ******** ACCOUNT NUMBER NOT FOUND ********\n";
    in.close();
    out.close();
    remove("bank.txt");
    rename("temp.txt", "bank.txt");
}

void deleterec()
{
    system("cls");
    ifstream in("bank.txt", ios::in);
    ofstream out("temp.txt", ios::out);
    int r;
    cout << "\n\n\n\n\t\t\t\t||****************************************************************||\n";
    cout << "\t\t\t\t||          **********   CLOSING AN ACCOUNT   **********          ||\n";
    cout << "\t\t\t\t||================================================================||";
    cout << "\n\t\t\t\t||________________________________________________________________||\n";
    cout << "\n\n\t\t\t\t             ENTER THE ACCOUNT NUMBER TO BE CLOSED :: ";
    cin >> r;
    int found = 0;
    bank s;
    while (in)
    {
        in.read((char *)&s, sizeof(s));
        if (in.eof())
            break;
        if (s.retano() != r)
        {
            out.write((char *)&s, sizeof(s));
        }
        else
        {
            cout << "\n\t\t\t\t     \t           ******** ACCOUNT CLOSED ********";
            found = 1;
        }
    } // while ends
    if (found == 0)
        cout << "\n\t\t\t\t     \t     ******** ACCOUNT NUMBER NOT FOUND ********\n";
    in.close();
    out.close();
    remove("bank.txt");
    rename("temp.txt", "bank.txt");
}

void withdraw()
{
    ifstream in("bank.txt", ios::in);
    ofstream out("temp.txt", ios::out);
    int r;
    cout << "\n\n\n\n\t\t\t\t||****************************************************************||\n";
    cout << "\t\t\t\t||         **********   WITHDRAWING AMOUNT    **********         ||\n";
    cout << "\t\t\t\t||================================================================||";
    cout << "\n\t\t\t\t||________________________________________________________________||\n";
    cout << "\n\n\t\t\t\t          ENTER THE ACCOUNT NUMBER TO BE DEBITED :: ";
    cin >> r;
    int found = 0;
    bank s;
    while (in)
    {
        in.read((char *)&s, sizeof(s));
        if (in.eof())
            break;
        if (s.retano() == r)
        {
            s.withdraw();
            out.write((char *)&s, sizeof(s));
            cout << "\n\n\t\t\t     ||****************************************************************||\n";
            cout << "\n\t\t\t\t******** CUSTOMER ACCOUNT DEBITED IN THE FILE DATABASE ********\n";
            found = 1;
        }
        else
            out.write((char *)&s, sizeof(s));
    } // while ends
    if (found == 0)
        cout << "\n\t\t\t\t     \t     ******** ACCOUNT NUMBER NOT FOUND ********\n";
    in.close();
    out.close();
    remove("bank.txt");
    rename("temp.txt", "bank.txt");
}

void loading()
{
    for (int v = 1; v <= 50; v++)
    {
        system("cls");
        cout << "\n\n\n\n\n\n";
        cout << endl
             << "\t\t\t\t";
        for (int e = 0; e < 50; e++)
            printf("=");
        cout << "\n\t\t\t\t\t     ACCESSING ADMIN PORTAL " << '\n'
             << '\t' << "\t\t\t";
        for (int j = 1; j <= v; j++)
            cout << "#";
        cout << "\n\n\t\t\t\t\t" << 2 * v << "%";
        if (v > 1 && v < 20)
            cout << "\n\t\t\t\tCreating Temporary files";
        else if (v > 20 && v < 40)
            cout << "\n\t\t\t\t\tAccessing Main Memory";
        else if (v > 40 && v < 48)
            cout << "\n\t\t\t\t\tAccessing Cache";
        else
            cout << "\n\t\t\t\t\tComplete. Press Enter to Continue ";
        sleep(1 - 0.00000000001);
    }
    sleep(1);
}

void intro()
{
    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t@@ ------------------------------------------------------------- @@\n";
    cout << "\t\t\t@@|                                           	                |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@|                                           	                |@@\n";
    cout << "\t\t\t@@|                                           	                |@@\n";
    cout << "\t\t\t@@|                                           	                |@@\n";
    cout << "\t\t\t@@|                          WELCOME TO                         |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@|                      BANKING SOLUTIONS                      |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@|                                                             |@@\n";
    cout << "\t\t\t@@ ------------------------------------------------------------- @@\n";
    cout << "\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\n\n\n\t\t\t||****************************************************************||\n";
    cout << "\t\t\t||                      MORE DETAILS .......                      ||\n";
    cout << "\t\t\t||================================================================||";
    getch();
}

class communityFacility
{
    int N;

public:
    communityFacility(int num)
    {
        N = num;
    }

    // Returns index of maximum value in net amount array
    int getMaxValIdx(int netAmount[])
    {
        int maxCreditIdx = 0;
        for (int i = 1; i < N; i++)
        {
            if (netAmount[i] > netAmount[maxCreditIdx])
            {
                maxCreditIdx = i;
            }
        }
        return maxCreditIdx;
    }

    // Returns index of minimum value in net amount array
    int getMinValIdx(int netAmount[])
    {
        int maxDebitIdx = 0;
        for (int i = 1; i < N; i++)
        {
            if (netAmount[i] < netAmount[maxDebitIdx])
            {
                maxDebitIdx = i;
            }
        }
        return maxDebitIdx;
    }

    // amount[i][j] implies the amount that person 'i' needs to pay to person 'j'
    void minimizeCashFlow(int **amount)
    {
        int netAmount[N] = {0};

        // net amt = all credits(amt to be received) - all debits(amt to pay)
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                netAmount[i] += (amount[j][i] - amount[i][j]);
            }
        }

        // maximum net amount => max creditor and minimum net amount => max debtor
        int maxCreditIdx = getMaxValIdx(netAmount), maxDebitIdx = getMinValIdx(netAmount);

        // Until all the amounts are not settled!
        while (netAmount[maxCreditIdx] != 0 && netAmount[maxDebitIdx] != 0)
        {
            int min_val = min(-netAmount[maxDebitIdx], netAmount[maxCreditIdx]);

            netAmount[maxCreditIdx] -= min_val;
            netAmount[maxDebitIdx] += min_val;

            cout << "\n\t\t\t\tPerson " << maxDebitIdx + 1 << " pays " << min_val << " to "
                 << "Person " << maxCreditIdx + 1 << endl;

            maxCreditIdx = getMaxValIdx(netAmount), maxDebitIdx = getMinValIdx(netAmount);
            sleep(2);
        }
    }
};

int distinct();
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int, int>> adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    system("cls");
    loading();
    intro();
    int n, choice;
    char ch;

    do
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t****************************************************************\n";
        cout << "\t\t\t\t |+| ******* INPUT THE FUNCTION YOU WANT TO PERFORM ******* |+|\n";
        cout << "\t\t\t\t |+| \t\t\t\t\t\t\t    |+|" << endl;
        cout << "\t\t\t\t |+| \t1 -> BANK TRANSACTIONS  \t\t\t    |+| \n";
        cout << "\t\t\t\t |+| \t2 -> COMMUNITY DEALINGS \t\t\t    |+| \n";
        cout << "\t\t\t\t |+| \t3 -> MANAGER            \t\t\t    |+| \n";
        cout << "\t\t\t\t |+| \t\t\t\t\t\t\t    |+|" << endl;
        cout << "\t\t\t\t****************************************************************\n";
        cout << "\t\t\t\t================================================================\n";
        cout << "\t\t\t\t\t   \t  ENTER YOUR CHOICE :: ";
        cin >> choice;

        if (choice == 1)
        {
            do
            {
                system("cls");
                cout << "\n\n\n\n\t\t\t\t****************************************************************\n";
                cout << "\t\t\t\t |+| ******* WELCOME TO BANK TRANSACTIONS SECTION ******* |+|\n";
                cout << "\n\n\n\n\t\t\t\t****************************************************************\n\n";

                cout << "\t\t\t\t |+| ******* INPUT THE FUNCTION YOU WANT TO PERFORM ******* |+|\n";
                cout << "\t\t\t\t |+| \t\t\t\t\t\t\t    |+|" << endl;
                cout << "\t\t\t\t |+| \t1 -> OPEN A NEW ACCOUNT \t\t\t    |+|\n";
                cout << "\t\t\t\t |+| \t2 -> DISPLAY ACCOUNT DETAILS \t\t\t    |+| \n";
                cout << "\t\t\t\t |+| \t3 -> CLOSE AN ACCOUNT \t\t\t\t    |+| \n";
                cout << "\t\t\t\t |+| \t4 -> MODIFY ACCOUNT DETAILS \t\t\t    |+| \n";
                cout << "\t\t\t\t |+| \t5 -> SEARCH AN ACCOUNT BY ACCOUNT NO \t\t    |+| \n";
                cout << "\t\t\t\t |+| \t6 -> SEARCH AN ACCOUNT BY ACCOUNT HOLDER's NAME     |+|\n";
                cout << "\t\t\t\t |+| \t7 -> WITHDRAW AN AMOUNT       \t\t\t |+|\n";
                cout << "\t\t\t\t |+| \t8 -> EXIT   \t\t\t\t\t    |+|\n";
                cout << "\t\t\t\t |+| \t\t\t\t\t\t\t    |+|" << endl;
                cout << "\t\t\t\t****************************************************************\n";
                cout << "\n\n\n\t\t\t\t================================================================\n";
                cout << "\t\t\t\t\t   \t  ENTER YOUR CHOICE :: ";
                cin >> n;
                cout << endl;
                switch (n)
                {
                case 1:
                {
                    add();
                    break;
                }

                case 2:
                {
                    show();
                    break;
                }

                case 3:
                {
                    deleterec();
                    break;
                }

                case 4:
                {
                    modify();
                    break;
                }

                case 5:
                {
                    searchano();
                    break;
                }

                case 6:
                {
                    searchname();
                    break;
                }

                case 7:
                {
                    withdraw();
                    break;
                }

                case 8:
                {
				    cout << "PROJECT MADE BY: \n\t\t* AYUSH JAIN \n\t\t* MUDIT GARG \n\t\t* DRISHIKA CHAUHAN \n\t\t* SIDDHARTH KAUSHIK" << endl;
				    cout << "\t\tBATCH: B-4" << endl;
					exit(0);
					break;
                }

                default:
                {
                    cout << "\n\t\t\t\t================================================================\n";
                    cout << "\t\t\t\t\t   \t      INVALID INPUT \n";
                    exit(0);
                    break;
                }
                }
                cout << endl
                     << "\n\t\t\t\t\t\tWOULD YOU LIKE TO CONTINUE [Y/N] :: ";
                cin >> ch;
            } while (ch == 'Y' || ch == 'y');
        }

        else if (choice == 2)
        {
            system("cls");
            do
            {
                system("cls");
                cout << "\n\n\n\n\t\t\t\t***************************************************************\n";
                cout << "\t\t\t\t |+| ******* WELCOME TO COMMUNITY DEALINGS SECTION ******* |+|\n";
                cout << "\t\t\t\t***************************************************************\n\n";

                cout << "\t\t    HERE, WE OFFER THE FEATURE TO MINIMIZE THE CASH FLOW AMONG COMMUNITY MEMBERS/GROUPS.";
                cout << "\n\t\t\t\t      THIS IS AN ADDITIONAL FEATURE PROVIDED BY OUR BANK.\n";
                cout << "\t\t\t\t\tWOULD YOU LIKE TO CHECK OUT THIS FEATURE? (Y/N) :: ";
                cin >> ch;

                if (ch == 'y')
                {
                    int num;
                    system("cls");
                    cout << "\n\n\n\n\t\t\t\t***************************************************************\n";
                    cout << "\t\t\tENTER THE NUMBER OF GROUP MEMBERS AMONG WHOM YOU WANT TO MINIMIZE THE CASH FLOW :: ";
                    cin >> num;

                    communityFacility cf(num);

                    int **amount;
                    amount = new int *[num];
                    for (int i = 0; i < num; i++)
                        amount[i] = new int[num];

                    for (int i = 0; i < num; i++)
                    {
                        for (int j = 0; j < num; j++)
                        {
                            cout << "\t\t\t\tENTER THE AMOUNT PERSON " << i + 1 << " NEEDS TO PAY TO PERSON " << j + 1 << ":: ";
                            cin >> amount[i][j];
                        }
                    }

                    cf.minimizeCashFlow(amount);
                }

                else if (ch == 'n')
                {
                    cout << "\t\t\t\tTHANK YOU FOR VISITING!" << endl;
                    exit(0);
                }

                else
                {
                    cout << "INVALID CHOICE!!!\n\nEnter your choice again..." << endl;
                }
            } while (ch != 'y' || ch != 'Y');
        }
        else if (choice == 3)
        {
            string password = "********";
            cout << "\n\t\t\t\t================================================================\n";
            cout << "\t\t\t\t\t\t  ENTER PASSWORD :: ";
            string pass;
            cin >> pass;
            while (pass != password)
            {
                cout << "\t\t\t\t\t\t  INCORRECT PASSWORD" << endl;
                cout << "\t\t\t\t\t\t  ENTER PASSWORD AGAIN\n\t\t\t\t\t\t     ";
                cin >> pass;
            }
            cout << "\n\t\t\t\t================================================================\n";
            cout << "\t\t\t\t\t1. FIND THE ORDER OF PEOPLE WE SHOULD APPROACH " << endl;
            cout << "\t\t\t\t\t2. HOW MUCH CAN WE EARN BY GIVING LOAN " << endl
                 << "\t\t\t\t\t\t  ENTER CHOICE :: ";
            int manchoice;
            cin >> manchoice;
            cout << "\n\t\t\t\t================================================================\n";
            bank b;
            if (manchoice == 1)
            {
                b.bitonicmain();
            }
            else if (manchoice == 2)
            {
                b.knapmain();
            }
        }

        else
        {
            cout << "\n\t\t\t\t================================================================\n";
            cout << "\t\t\t\t\t   \t      INVALID INPUT \n";
            cout << "Enter your choice again!!!\n";
        }
    } while (choice != 1 || choice != 2 || choice != 3);

    getch();
}
