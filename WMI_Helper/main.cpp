#include <iostream>
using namespace std;

#include "WMI_Helper.h"

int main()
{
	try
	{
		WMI_Helper wmi("root\\CIMV2\\Applications\\Games", "Game");
		std::vector<std::string> values;
		values.push_back("Name");
		WMI_Helper::wmiValues vals1 = wmi.request(values);

		std::vector<std::string> values2;
		values2.push_back("GameInstallPath");
		WMI_Helper::wmiValues vals = wmi.request(values2);

		for(unsigned int i = 0; i < vals.size(); i++)
		{
			WMI_Helper::wmiValue val = vals.at(i);
			WMI_Helper::wmiValue::iterator itr;

			for(itr = val.begin(); itr != val.end(); itr++)
			{
				std::cout << itr->first << ": ";
				std::wcout << itr->second.bstrVal << std::endl;
			}
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");

	return 0;
}