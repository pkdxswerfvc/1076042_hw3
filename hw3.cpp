// 1076042 hw3 
// LRU Algorithm

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <time.h>
#pragma  warning (disable:4996)

using namespace std;

void read_file(char filename[]);

vector<int> page_seq;
int number_of_pages = 0;
int number_of_frames = 0;
int miss = 0;
char filename_output[40] = "";

ofstream write_file;

class page_table {
public:
	int page_fault = 0, position = 0, index = 0, index_1 = 0;
	int freq_array[1000];
	int pages[1000];
	int frames[1000];

	page_table(int a, int b) {
		number_of_pages = a;
		number_of_frames = b;
		page_fault = number_of_frames;

		for (int i = 0; i < number_of_frames; i++)
		{
			frames[i] = -1;
			freq_array[i] = 0;
		}
	}

	void input_pages() {
		for (int i = 0; i < number_of_pages; i++)
		{
			pages[i] = page_seq[i];
		}
	}

	void intialize() {
		page_fault = 0;
		position = 0;
		index = 0;
		index_1 = 0;



		for (int i = 0; i < number_of_frames; i++)
		{
			frames[i] = pages[i];
			for (int j = 0; j <= i; j++)
			{
				freq_array[j] += 1;
			}
			show_frames();
			cout << endl;
			write_file << endl;
		}
	}

	bool do_check(int i1) {
		for (int i = 0; i < number_of_frames; i++)
		{
			if (frames[i] == pages[i1])
			{
				index_1 = i;
				return true;
			}
		}
		return false;
	}

	void out(int i) {
		freq_array[i] = 0;
	}

	int biggest() {
		int max = freq_array[0];
		for (int i = 0; i < number_of_frames; i++)
		{
			if (max <= freq_array[i])
			{
				max = freq_array[i];
				index = i;
			}
		}
		return index;
	}

	void show_frames() {
		for (int i = 0; i < number_of_frames; i++)
		{
			if (frames[i] == -1) {
				cout << " ";
				write_file << " ";
			}
			else {
				cout << frames[i] << " ";
				write_file << frames[i] << " ";
			}
		}
	}

	int eelru_algorithm() {
		for (int i = number_of_frames; i < number_of_pages; i++)
		{
			if (do_check(i) == true)
			{
				out(index_1);

				for (int j = 0; j < number_of_frames; j++)
				{
					if (index_1 == j)
					{
						continue;
					}
					freq_array[j] += 1;
				}
				show_frames();
				cout << endl;
				write_file << endl;
				continue;
			}
			else {
				position = biggest();

				frames[position] = pages[i];
				out(position);
				for (int j = 0; j < number_of_frames; j++)
				{
					if (position == j)
					{
						continue;
					}
					freq_array[j] += 1;
				}
				page_fault++;
			}
			show_frames();
			cout << "\toccur, Now page fault: " << page_fault << endl;
			write_file << "\toccur, Now page fault: " << page_fault << endl;
		}
		return page_fault;
	}
};


int main() {
	for (int i = 1; i <= 7; i++) {
		double START, END;
		START = clock();

		char test_case[] = "test_case.txt";
		char test_case_1[] = "test_case_100.txt";
		char test_case_2[] = "test_case_200.txt";
		char test_case_3[] = "test_case_300.txt";
		char test_case_4[] = "test_case_400.txt";
		char test_case_5[] = "test_case_500.txt";
		char test_case_6[] = "test_case_600.txt";
		char test_case_7[] = "test_case_700.txt";

		switch (i)
		{
		case 1:
			cout << "File name: " << test_case_1 << endl << endl;
			read_file(test_case_1);
			break;
		case 2:
			cout << "File name: " << test_case_2 << endl << endl;
			read_file(test_case_2);
			break;
		case 3:
			cout << "File name: " << test_case_3 << endl << endl;
			read_file(test_case_3);
			break;
		case 4:
			cout << "File name: " << test_case_4 << endl << endl;
			read_file(test_case_4);
			break;
		case 5:
			cout << "File name: " << test_case_5 << endl << endl;
			read_file(test_case_5);
			break;
		case 6:
			cout << "File name: " << test_case_6 << endl << endl;
			read_file(test_case_6);
			break;
		case 7:
			cout << "File name: " << test_case_7 << endl << endl;
			read_file(test_case_7);
			break;
		default:
			break;
		}

		cout << "\nFrames: " << endl;
		page_table p(number_of_pages, number_of_frames);
		p.input_pages();
		p.intialize();
		miss = p.eelru_algorithm();
		END = clock();

		cout << "\nTotal page fault: " << miss << endl << endl;

		cout << "Output file: " << filename_output << endl;
		write_file << "\nTotal page fault: " << miss << endl;
		cout << "Hit: " << number_of_pages - miss << "   Hit ratio: " << fixed << setprecision(2) << ((double)number_of_pages - (double)miss) / (double)number_of_pages << endl;
		write_file << "Hit: " << number_of_pages - miss << "   Hit ratio: " << fixed << setprecision(2) << ((double)number_of_pages - (double)miss) / (double)number_of_pages << endl;
		cout << "Miss: " << miss << "   Miss ratio: " << fixed << setprecision(2) << (double)miss / (double)number_of_pages << endl << endl;
		write_file << "Miss: " << miss << "   Miss ratio: " << fixed << setprecision(2) << (double)miss / (double)number_of_pages << endl << endl;
		cout << "Execution time: " << (END - START) / CLOCKS_PER_SEC << " sec" << endl << endl;
		write_file << "Execution time: " << (END - START) / CLOCKS_PER_SEC << " sec" << endl;
		write_file.close();

		memset(filename_output, '\0', sizeof(filename_output));
		page_seq.clear();
		number_of_pages = 0;
		number_of_frames = 0;
	}

	system("pause");
	return 0;
}


void read_file(char filename[]) {

	int line_count = 0;

	ifstream infile(filename);

	if (!infile) {    // Can not open file
		cout << "Open file error..." << endl << endl;
		system("pause");
		exit(0);
	}
	else {    // Open file success

		string line;
		char temp[10];
		string string_split;

		while (getline(infile, line)) {
			line_count++;
			istringstream iss(line);

			if (line_count == 1) {
				iss >> temp;
				number_of_pages = atoi(temp);
				memset(temp, 0, sizeof(temp));
			}
			else if (line_count == 2) {
				iss >> temp;
				number_of_frames = atoi(temp);
				memset(temp, 0, sizeof(temp));
			}
			else {
				while (getline(iss, string_split, ' ')) {
					strncpy(temp, string_split.c_str(), sizeof(string_split.c_str()));
					page_seq.push_back(atoi(temp));

					memset(temp, 0, sizeof(temp));
				}
			}
		}
		infile.close();
	}


	char char_pages[10];
	itoa(number_of_pages, char_pages, 10);

	strcat(filename_output, char_pages);
	strcat(filename_output, "_eelru_out.txt");

	cout << filename_output << endl;

	write_file.open(filename_output);

	cout << "Number of pages: " << number_of_pages << endl;
	write_file << "Number of pages: " << number_of_pages << endl;
	cout << "Number of frames: " << number_of_frames << endl;
	write_file << "Number of frames: " << number_of_frames << endl;
	cout << "Refernec string: ";
	write_file << "Refernec string: ";
	for (int i = 0; i < page_seq.size(); i++) {
		cout << page_seq[i] << " ";
		write_file << page_seq[i] << " ";
	}
	cout << endl;
	write_file << endl;
}


