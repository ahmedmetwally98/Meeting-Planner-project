/*
 * main.cpp
 *
 *  Created on: May 7, 2020
 *      Author: student
 */

#include"BST.h"

using namespace std;

ofstream outputFile;
int quotePos;

int Argu_Num_of_valid_title(char strargu[])
{
	int counter=0;
	int argunum=0;
	while(counter <= quotePos)
	{
		counter++;
		if(counter > quotePos)
		{
			argunum=argunum+1;
		}
	}
	for(; strargu[counter]==' '||strargu[counter]=='\t'; counter++);
	if(strargu[counter]=='\0')
	{
		return argunum;
	}
	else
	{
		while(!(strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
		{
			counter++;
			if((strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
			{
				argunum=argunum+1;
			}
		}
		for(; strargu[counter]==' '||strargu[counter]=='\t'; counter++);
		if(strargu[counter]=='\0')
		{
			return argunum;
		}
		else
		{
			while(!(strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
			{
				counter++;
				if((strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
				{
					argunum=argunum+1;
				}
			}
			for(; strargu[counter]==' '||strargu[counter]=='\t'; counter++);
			if(strargu[counter]=='\0')
			{
				return argunum;
			}
		}
	}
	//if we reach there then we got invalid number of argument so we return number larger than expected
	return 4;
}

int Argu_Num_of_invalid_title(char strargu[])
{
	int counter=0;
	int argunum=0;
	while(!(strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
	{
		counter++;
		if((strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
		{
			argunum=argunum+1;
		}
	}
	for(; strargu[counter]==' '||strargu[counter]=='\t'; counter++);
	if(strargu[counter]=='\0')
	{
		return argunum;
	}
	else
	{
		while(!(strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
		{
			counter++;
			if((strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
			{
				argunum=argunum+1;
			}
		}
		for(; strargu[counter]==' '||strargu[counter]=='\t'; counter++);
		if(strargu[counter]=='\0')
		{
			return argunum;
		}
		else
		{
			while(!(strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
			{
				counter++;
				if((strargu[counter]==' '||strargu[counter]=='\t'||strargu[counter]=='\0'))
				{
					argunum=argunum+1;
				}
			}
			for(; strargu[counter]==' '||strargu[counter]=='\t'; counter++);
			if(strargu[counter]=='\0')
			{
				return argunum;
			}
		}
	}
	//if we reach there then we got invalid number of argument so we return number larger than expected
	return 4;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{//check for number of arguments passed to main function
		cout<<"Invalid number of files"<<endl;
		return 0;
	}

	ifstream cmdFile;
	cmdFile.open(argv[1]);
	outputFile.open(argv[2]);
	//check if the input file exist in the right directory or not
	if(cmdFile.fail())
	{
		cerr << "Input file not found" << endl;
		return 0;
	}
	else
	{
		char cmdline[1000]; //to read cmdfile char by char
		BST planner;
		string strmeetingTitle = "\0", cmdtype = "\0";
		string strday = "\0";
		string strhour = "\0";
		string strcmds[5] = {"ADD", "MOD", "Find", "DEL" ,"Print"};
		//opening command file and reading it
		while(!cmdFile.eof() && cmdFile.getline(cmdline, 1000))
		{//reading command file line by line
			strmeetingTitle = "\0", cmdtype = "\0";
			strday = "\0";
			strhour = "\0";
			char arguStr[1000] = "\0";
			int quotesNum = 0;
			bool cmdFlag = true; //if become false then this give command error
			bool titleFlag = true; //if become false then this give title error
			bool arguFlag = true;  //if become false then this give argument error
			bool dayFlag = true;   //if become true then this give day error
			bool hourFlag = true;  //if become then this give hour error
			int day=0, hour=0;
			int i=0, index=0, cmd_index=0;
			int arguNum = 0, title_size = 0;
			if(cmdline[i]!='\0' && cmdline[i]!='\r')
			{
				while(true)
				{//reading one line
					for(; cmdline[i]==' '||cmdline[i]=='\t'; i++);
					while(cmdline[i]!=' ' && cmdline[i]!='\t' && cmdline[i]!='\0' && cmdline[i]!='\r')
					{
						cmdtype+=cmdline[i];
						i++;
					}

					if(cmdline[i]=='\0'|| cmdline[i]=='\r')
					{
						break;
					}

					for(; cmdline[i]==' '||cmdline[i]=='\t'; i++);
					if(cmdline[i]=='\0'||cmdline[i]=='\r')
					{
						break;
					}
					else
					{
						if((cmdtype=="Print") && ((cmdline[i]!='\0') || (cmdline[i]!='\r')))
						{
							arguFlag=false;
							break;
						}
					}
					while(cmdline[i]!='\0' && cmdline[i]!='\r')
					{//reading all arguments in one array of char
						arguStr[index] = cmdline[i];
						if(arguStr[index]=='"')
						{
							quotesNum++;
							quotePos=index;
						}
						i++;
						index++;
						if(cmdline[i]=='\0'||cmdline[i]=='\r')
						{//put end of the arguments' string
							arguStr[index]='\0';
							break;
						}
					}
					if(cmdtype=="ADD" || cmdtype=="MOD")
					{//here we will check for title
						if(quotesNum >= 2)
						{
							if(arguStr[0]=='"')
							{
								if(arguStr[quotePos+1]=='\0')
								{//invalid arguments
									arguFlag=false;
									break;
								}
								if(arguStr[quotePos+1]==' ' || arguStr[quotePos+1]=='\t')
								{//valid title. so, let's check the no. of arguments
									arguNum=Argu_Num_of_valid_title(arguStr);
									if(arguNum != 3)
									{//invalid no. of arguments

										arguFlag= false;
										break;
									}
								}
								else
								{//invalid title. so, let's check the no. of arguments
									arguNum=Argu_Num_of_invalid_title(arguStr);
									if(arguNum != 3)
									{
										arguFlag=false;
										break;
									}
									else
									{
										titleFlag=false;
									}
								}
							}
							else
							{//invalid title, as position of first double quote is wrong. then we need to check no. of arguments
								arguNum=Argu_Num_of_invalid_title(arguStr);
								if(arguNum != 3)
								{
									arguFlag=false;
									break;
								}
								else
								{
									titleFlag = false;
								}
							}
						}
						else
						{//invalid title. then we need to check no. of arguments
							arguNum=Argu_Num_of_invalid_title(arguStr);
							if(arguNum != 3)
							{
								arguFlag=false;
								break;
							}
							else
							{
								titleFlag=false;
							}
						}
					}
					else
					{
						if(cmdtype=="DEL"||cmdtype=="Find")
						{
							arguNum=Argu_Num_of_invalid_title(arguStr);
							if(arguNum != 2)
							{//invalid no. of arguments
								arguFlag=false;
								break;
							}
						}
					}
					index=0;
					if(cmdtype == "ADD" || cmdtype == "MOD")
					{//reading title
						for(; arguStr[index]==' '||arguStr[index]=='\t'; index++);
						if(titleFlag)
						{
							while(index <= quotePos)
							{//reading meeting title
								strmeetingTitle += arguStr[index];
								index++;
							}
						}
						else
						{
							while(!(arguStr[index] ==' ' || arguStr[index]=='\t' || arguStr[index]=='\0'))
							{//reading meeting title
								strmeetingTitle += arguStr[index];
								index++;
							}
						}
						title_size = strmeetingTitle.size();
						if(strmeetingTitle[0] != '"' || strmeetingTitle[title_size-1] != '"')
						{
							titleFlag = false;
						}
					}
					//////////////////////////////////////////////////////////////////////
					for(; arguStr[index]==' '||arguStr[index]=='\t'; index++);
					while(!(arguStr[index] ==' ' || arguStr[index]=='\t' || arguStr[index]=='\0'))
					{//reading day
						if((arguStr[index]>= 48 && arguStr[index] <= 57))
						{//this condition to guarantee that day will be always a number
							strday += arguStr[index];
						}
						else
						{
							dayFlag = false;
						}
						index++;
					}
					if(dayFlag != false && strday != "\0")
					{//converting day from string to integer
						day = stoi(strday);
						//checking range of days
						if(!(day >= 1 && day <= 365))
						{
							dayFlag = false;
						}
					}
					//////////////////////////////////////////////////////////////////////
					for(; arguStr[index]==' '||arguStr[index]=='\t'; index++);
					while(!(arguStr[index] ==' ' || arguStr[index]=='\t' || arguStr[index]=='\0'))
					{//reading hour
						if((arguStr[index]>= 48 && arguStr[index] <= 57))
						{//this condition to guarantee that hour will be always a number
							strhour += arguStr[index];
						}
						else
						{
							hourFlag = false;
						}
						index++;
					}
					if(hourFlag != false && strhour != "\0")
					{//converting hour from string to integer
						hour = stoi(strhour);
						//checking range of hours
						if(!(hour >= 0 && hour <= 23))
						{
							hourFlag = false;
						}
					}
				}
				for(cmd_index=0; cmd_index<5; cmd_index++)
				{
					if(cmdtype == strcmds[cmd_index])
					{
						cmdFlag = true;
						break;
					}
					cmdFlag = false;
				}
				if(cmdFlag == false)
				{
					cout << "Invalid command" << endl;
					outputFile << "Invalid command" << endl;
					//we go to the next line as the command of this line is not valid
					continue;
				}
				if((cmdtype == "ADD" || cmdtype == "MOD" ) && arguNum != 3)
				{
					arguFlag = false;
				}
				if((cmdtype == "Find" || cmdtype == "DEL") && arguNum != 2)
				{
					arguFlag = false;
				}
				if(cmdtype == "Print" && arguNum != 0)
				{
					arguFlag = false;
				}
				if(arguFlag != false && cmdFlag != false)
				{//here no. of arguments is correct and command is correct and checking other flags
					if(titleFlag == false)
					{
						cout << "Invalid title" <<endl;
						outputFile << "Invalid title" <<endl;
					}
					if(dayFlag == false)
					{
						cout << "Invalid day" <<endl;
						outputFile << "Invalid day" <<endl;
					}
					if(hourFlag == false)
					{
						cout << "Invalid hour" <<endl;
						outputFile << "Invalid hour" <<endl;
					}
				}
				else
				{
					if(arguFlag==false)
					{
						cout << "Invalid arguments" << endl;
						outputFile << "Invalid arguments" << endl;
					}
				}
				if(cmdFlag != false && arguFlag != false && titleFlag != false && dayFlag != false && hourFlag != false)
				{
					switch(cmd_index)
					{
					case 0://for command ADD
						planner.insertLeaf(strmeetingTitle, day, hour);
						break;

					case 1://for command MOD
						planner.find_modifyNode(strmeetingTitle, day, hour, "MOD");
						break;

					case 2://for command Find
						planner.find_modifyNode(strmeetingTitle, day, hour, "Find");
						break;

					case 3://for command DEL
						planner.deleteLeaf(day, hour);
						break;
					case 4://for command Print
						planner.printTree();
						break;
					}
				}
			}
			else
			{//get the next line as this line is empty
				continue;
			}

		}
	}

	cmdFile.close();
	outputFile.close();
  return 0;
}



