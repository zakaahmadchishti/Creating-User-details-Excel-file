/// Project
//Copyrights reserved  www.zakaahmadchishti.tk
//Copyrights Commerical Labrarory Used libxl.com project
//source file forwarded to zac2486@gmail.com
// pc_VQUB3RG created under upper account details




#include<iostream>
#include<string>
#include<fstream>
#include<libxl.h>
#include<direct.h>
#include <windows.h>
#include <cstdlib>

using namespace std;
using namespace libxl;

int secondsc;


class design
{
public:
	void maindesign() { cout << "1. Sign in" << endl; cout << "2. Sign up" << endl; }
	void username() { cout << "Enter Username :"; }
	void passsword() { cout << "Enter Password :"; }
	void conformpasssword() { cout << "Enter Password Again :"; }
	void fullname() { cout << "Enter Full Name :"; }
	void fullnamewe() { cout << "Enter Name we say :"; }
	void address() { cout << "Enter Address :"; }
	void balancecheck() { cout << "Your Current Balance (R.S): "; }
	void accountnumber() { cout << "Your Account Number :"; }
	void transationamount() { cout << "Transatation amount: "; }
	void menu()
	{
		cout << "1. Balance Check" << endl;
		cout << "2. Transation" << endl;
		cout << "3. Transation History " << endl;
		cout << "4. Bill payment" << endl;
		cout << "5. Setting" << endl;
		cout << "0. Log out" << endl;
	}
	void accountcreatedsuss(){ cout << "Account Created Sussfully !" << endl; }
	void usernamecheckfirst3char() {cout << "Sorry Username First three Characters Must be Albatic" << endl;}
	void enteragain(){ cout << "Enter Again Please !" << endl; }
	void redirecttologin(){ cout << "Redirect to Login Page" << endl; }
	void passwordcompare(){ cout << "Password Not Match" << endl; }
	void backalert(){ cout << "Imigate Back deleted your processing Data & Steps" << endl; }
	void usernamealreadyexist() { cout<<"username already Exist !"; }
	void usernamechecklessthan(){ cout << "Enter Username is less than 8 characters ! Sorry" << endl; }
	void usernamechecksymbol(){ cout << "Username Does't consist of Sysmbols or Space ! Error " << endl; }
	void actiondeleted() { cout << "Action Not Completed !" << endl; }
};





class foldermanager
{


public:
	string number;

	bool newfoldercreater()
	{
		string accountnumber = accountnumbergenertaor();
		mkdir("c:\\Backup");
		mkdir("c:\\Backup\\total userdata");
		string path = "c:\\Backup\\total userdata\\" + accountnumber;
		mkdir(path.c_str());
		return true;
	}

	string accountnumbergenertaor()
	{
		string h; h = to_string(secondsc);
		number = h + "1" + h + "2" + h + "3" + h + "4" + h + "5" + h + "6" + h + "7" + h;
		return number;
	}

	void excelhistorytrans()
	{
		Book* book = xlCreateXMLBook();
		if (book)
		{
			Font* boldFont = book->addFont();
			boldFont->setBold();

			Font* titleFont = book->addFont();
			titleFont->setName(L"Zaka");
			titleFont->setSize(16);

			Format* titleFormat = book->addFormat();
			titleFormat->setFont(titleFont);

			Format* headerFormat = book->addFormat();
			headerFormat->setAlignH(ALIGNH_CENTER);
			headerFormat->setBorder(BORDERSTYLE_THIN);
			headerFormat->setFont(boldFont);
			headerFormat->setFillPattern(FILLPATTERN_SOLID);
			headerFormat->setPatternForegroundColor(COLOR_TAN);

			Format* descriptionFormat = book->addFormat();
			descriptionFormat->setBorderLeft(BORDERSTYLE_THIN);

			Format* amountFormat = book->addFormat();
			amountFormat->setAlignH(ALIGNH_CENTER);
			amountFormat->setNumFormat(NUMFORMAT_NUMBER_SEP_D2);
			amountFormat->setBorderLeft(BORDERSTYLE_THIN);
			amountFormat->setBorderRight(BORDERSTYLE_THIN);

			Format* totalLabelFormat = book->addFormat();
			totalLabelFormat->setBorderTop(BORDERSTYLE_THIN);
			totalLabelFormat->setAlignH(ALIGNH_RIGHT);
			totalLabelFormat->setFont(boldFont);

			Format* totalFormat = book->addFormat();
			totalFormat->setNumFormat(NUMFORMAT_NUMBER_SEP_D2);
			totalFormat->setBorder(BORDERSTYLE_THIN);
			totalFormat->setFont(boldFont);
			totalFormat->setFillPattern(FILLPATTERN_SOLID);
			totalFormat->setPatternForegroundColor(COLOR_YELLOW);

			Format* signatureFormat = book->addFormat();
			signatureFormat->setAlignH(ALIGNH_CENTER);
			signatureFormat->setBorderTop(BORDERSTYLE_THIN);

			Sheet* sheet = book->addSheet(L"Invoice");
			if (sheet)
			{
				sheet->writeStr(2, 1, L"Iqra University Islamabad", titleFormat);

				sheet->writeStr(4, 1, L"Name:");
				sheet->writeStr(5, 1, L"Account:");

				sheet->writeStr(7, 1, L"Description & Details", headerFormat);
				sheet->writeStr(7, 2, L"Amount", headerFormat);
				sheet->writeStr(7, 3, L"IP Login PC", headerFormat);
				sheet->writeStr(7, 4, L"IP Source", headerFormat);

				sheet->writeStr(8, 1, L"", descriptionFormat);
				sheet->writeNum(8, 2, 0, amountFormat);
				sheet->writeStr(9, 1, L"", descriptionFormat);
				sheet->writeNum(9, 2, 0, amountFormat);
				sheet->writeStr(10, 1, L"", descriptionFormat);
				sheet->writeNum(10, 2, 0, amountFormat);

				sheet->writeStr(11, 1, L"Total:", totalLabelFormat);
				sheet->writeFormula(11, 2, L"=SUM(C9:C11)", totalFormat);

				sheet->writeStr(14, 2, L"Signature", signatureFormat);

				sheet->setCol(1, 1, 40);
				sheet->setCol(2, 2, 15);
			}
			book->save(L"Transations.xlsx");
		}
	}


	

};

























class signup
{ protected:string userentername, username; int asd=0;design z;
public:
//////////////////////////////////////////////////////////////////////////////////////////////////////
	bool Inputsignup()
	{
		if (dealingwithusername() == true)
		{
			if (dealingwithpassword() == true)
			{
				z.accountcreatedsuss(); return true;
			}
			else {
				if (asd == 1) { Inputsignup(); }
				if (asd == 2 || asd == 3) { z.actiondeleted(); }
			}

		}

	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	bool dealingwithusername()
	{
		z.username();
		cin >> userentername;
		if (Inputfilter(userentername) == true)
		{
			if (dealingwithusernameadvance(userentername) == true)
			{
				return true;
			}
			else { dealingwithusername(); }
		}
		else return false;	
	}
	/////////////////////////////////////////////////////////////////////////////////////////////
	bool dealingwithusernameadvance(string userentername)
	{
		if (usernamesymbolcheck(userentername) == true)
		{
			username = usernamecaps(userentername);
			if (usernameavaliable(username) == true)
			{
				
				return true;
			}
		}
		return false;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool dealingwithpassword()
	{
		string pass; z.passsword(); cin >> pass;
		if (Inputfilter(pass) == true)
		{
			if (dealingwithpasswordadvance(pass) == true)
			{
				return true;
			}
			else { z.passwordcompare(); dealingwithpassword();  }
		}
		else
		{
			if (asd == 1) { cout << "Single back" << endl; }


			return false;
		}
	}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool dealingwithpasswordadvance(string pass)
	{
		string passa; z.conformpasssword(); cin >> passa;
		if (pass == passa)
		{
			savedata(username); foldermanager j; j.newfoldercreater();
			return true;
		}
		else return false;

	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
	   bool usernamesymbolcheck(string userentername)
	   {   int ze = 0;
		   if (userentername.size() >= 4)
		   {   for (int i = 0; i < userentername.size(); i++)
			   {   char albatichalder = userentername[i];// pick letter from string one by one
				   if (albatichalder == '!' || albatichalder == '@' || albatichalder == '#' || albatichalder == '$' || albatichalder == '%' || albatichalder == '^' || albatichalder == '&' || albatichalder == '*' || albatichalder == '(' || albatichalder == ')' || albatichalder == '+' || albatichalder == '=' || albatichalder == ';' || albatichalder == ':' || albatichalder == '<' || albatichalder == '>' || albatichalder == ',' || albatichalder == '?' || albatichalder == '/' || albatichalder == ' ')
				   {ze = ze + 1;}
				   if (i < 4)
				   { if (albatichalder == '0' || albatichalder == '1' || albatichalder == '2' || albatichalder == '3' || albatichalder == '4' || albatichalder == '5' || albatichalder == '6' || albatichalder == '7' || albatichalder == '8' || albatichalder == '9')
					   {   z.usernamecheckfirst3char(); z.enteragain();return false;}
				   }
			   }
			   if (ze > 0)
			   {z.usernamechecksymbol();
			   cout << "Number of Symbols =" << ze << endl; z.enteragain();
				return false;
			   }
			   else{return true;}
		   }
		   else{ z.usernamechecklessthan(); return false;}
	   }
//////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
	   bool usernameavaliable(string username)
	   {   string line; int offset = 0;fstream file;
		   file.open("name.txt", ios::in);
		   while (!file.eof())
		   {
			   getline(file, line);
			   if (line == username)
			   {z.usernamealreadyexist();
			   z.enteragain();
			   return false;}
		   }
		   file.close();
		   return true;   
	   }
//////////////////////////////////////////////////////////////////////////////////////
	
///////////////////////////////////////////////////////////////////////////////////////////////////////
	   bool savedata(string username)
	   {
		   string a = ""; int b = 0;
		   ifstream cfile;
		   cfile.open("configdata.txt", ios::in);
		   getline(cfile, a);
		   b = atoi(a.c_str());
		   b = 1 + b;
		   secondsc = b;
		   cfile.close();
		   ofstream csfile;
		   csfile.open("configdata.txt", ios::out);
		   csfile << b;
		   ofstream Myfile;
		   Myfile.open("name.txt", ios::app);
		   Myfile << username << endl;
		   Myfile << b << endl;
		   return true;
	   }
///////////////////////////////////////////////////////////////////////////////////////////////////////
	   string usernamecaps(string userentername)
	   {    string username;
		   for (int i = 0; i < userentername.size(); i++)
		   {
			   char albatichalder = userentername[i];
			   albatichalder = toupper(albatichalder);username += albatichalder;
		   }
		   return username;
	   }
/////////////////////////////////////////////////////////////////////////////////////////////
	bool Inputfilter(string as)
	{
		if (as == "0" || as == "00" || as == "000")
		{
			if (as == "0")
			{z.backalert(); asd = 1;return false;}
			if (as == "00")
			{z.backalert();asd = 2;return false;}
			if (as == "000")
			{z.backalert();asd = 3;return false;}
         }
		return true;
	}
////////////////////////////////////////////////////////////////////////////////////////////////

};

































































class InputHandler
{
public:design f;string in;

	string mainmenu()
	{   f.maindesign();
		 cin >> in;
		if (in == "1" | in == "2")
		{if (in == "1"){                          }
			if (in == "2"){signup s;s.Inputsignup();foldermanager f; f.newfoldercreater();}
			
			in.clear();
			return in;
		}
		else
		{cout << "Input Don't Exist Enter Again !" << endl;system("cls"); mainmenu();}
	}
};






















void main()
{
	InputHandler i;
	i.mainmenu();
	
	system("pause");



}