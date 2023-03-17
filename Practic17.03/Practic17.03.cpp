#include <iostream>
#include <string>

using namespace std;
#define CHOICE 3

#if CHOICE == 1
/*
Дан текст программы на С++. Комментарии начинаются
с "//" и продолжаются до конца текущей строки
или начинаются с "/" и заканчиваются "/". В последнем
случае комментарии могут быть в середине строки или
располагаться на нескольких строках.
Написать функцию, удаляющую комментарии.
*/

int main()
{
	setlocale(LC_ALL, "");
	string str = R"(/*У Лукоморья*/ дуб зеленый.
//Златая цепь на дубе том.
И днем/*, и ночью, кот ученый,
Все ходит по це*/пи кру//гом.
            //А.С. Пушкин)";
	cout << str << endl << endl;

	int index;
	/*while ((index = str.find("//")) != -1 ||
		(index = str.find("/*")) != -1 ||
		(index = str.find("")) != -1) {
		str.erase(index, 2);
		
	}*/
	//while ((index = str.find_first_of("*/")) != -1) {
	//	str.erase(index, 1);
	//}

	int start_index, end_index;
	while ((start_index = str.find("/*")) != -1 &&
		(end_index = str.find("*/")) != -1) {
		str.erase(start_index, end_index - start_index + 2);
	}
	cout << str << endl << endl;
	while ((start_index = str.find("//")) != -1) {
		end_index = str.find("\n", start_index);
		str.erase(start_index, end_index - start_index + 1);
	}
	cout << str << endl;
}

#elif CHOICE == 2

/*
Написать функцию, принимающую в качестве параметров 
две строки и возвращающую копию первого
параметра, все вхождения второго параметра в которой
взяты в «()»
Например, если параметрами были строки
"abaracadabra" и "ab",
то вернуть надо
"(ab)aracad(ab)ra".
*/

string new_str(string str, string substr) {
	int i = 0;
	while ((i = str.find(substr, i)) != -1)
	{
		str.insert(i, "(");
		str.insert(i + substr.size()+1, ")");
		i += substr.size() + 1;
	}
	return str;
}

int main() {
	cout << new_str("abaracadabra", "ab") << endl << endl;
	cout << new_str("qwerty ytrewwq", "qwerty") << endl << endl;
	cout << new_str("qazwsxedc vfredc xswqeeeazx", "e") << endl << endl;
}

#elif CHOICE == 3

/*
В строке текста встречаются выражения, 
представляющие суммы и разности двух натуральных чисел в виде
n1+n2, n1-n2.
Написать функцию, заменяющую выражения их числовыми значениями.
Например, для строки
"alpha 5+26 beta 72-35 gamma 32+45 etc"
результат должен быть
"alpha 31 beta 37 gamma 77 etc".
*/

string add(string a, string b){
	return to_string(stoi(a) + stoi(b));
}
string sub(string a, string b) {
	return to_string(stoi(a) - stoi(b));
}

int main() {
	string s1 = "alpha 5+26 beta 72-35 gamma 32+45 etc";
	
	//leftNum = stoi(s1.substr(0, s1.find("+")));
	//rightNum = stoi(s1.substr(s1.find("+") + 1));
	//cout << leftNum + rightNum;
	int znak;

	string leftNum{ "" }, rightNum{ "" };
	while ((znak = s1.find_first_of("+-")) != -1)
	{

		int l, r, i = znak-1;
		while(isdigit(s1.at(i))) {
			leftNum.insert(leftNum.begin(), s1.at(i));
			i--;
		}
		l = i;
		i = znak + 1;
		while (isdigit(s1.at(i)))
		{
			rightNum.push_back(s1.at(i));
			//rightNum.insert(rightNum.end(), s1.at(i));
			i++;
		}
		r = i;
		if (s1.at(znak) == '+') 
		{ 
			s1.replace(l+1, r-l-1, add(leftNum, rightNum)); 
		}
		else 
		{ 
			s1.replace(l+1, r - l-1, sub(leftNum, rightNum));
		}
		leftNum.clear();
		rightNum.clear();
	}
	cout << s1;
}
#endif