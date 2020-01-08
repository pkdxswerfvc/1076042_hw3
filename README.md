# 1076042 HW3 Cache replacement - LRU
此檔案介紹如何使用此程式

## 執行方式
輸入 input 檔案檔名。

## 程式流程
	1. 將存在於實體記憶體頁框中最久沒用到的分頁給取代掉
	2. 使用計數變數(Counter)去儲存每個在頁框內的分頁使用後閒置的時間

## FUNCTION
void read_file(char filename[]); // 讀檔  
class page_table {};  // 紀錄 page  
int main(); // 執行 LRU 替換  

## INPUT FILE
輸入檔包含 `page 數量` 及 `page`。
* **Example:** test_case100.txt ~ test_case700.txt  

		100
 	 	5
  		4 2 1 4 4 3 3 4 2 3 1 1 0 4 4 3 1 4 3 4 3 0 1 5 1 1 1 4 1 1 5 0 3 3 2 3 1 4 6 6 4 0 2 3 3 0 4 2 4 0 4 4 5 1 5 2 6 0 6 3 2 1 0 4 1 6 4 3 3 5 4 2 5 5 6 4 2 2 4 5 6 2 0 2 6 2 4 6 3 3 2 2 4 0 0 4 4 0 6 4
   
		200
		5
		3 2 1 4 3 3 5 2 6 6 6 5 2 0 0 1 1 5 4 5 6 0 1 5 2 4 1 6 1 1 1 0 4 4 6 0 3 2 1 6 5 5 0 3 3 4 4 5 1 3 0 5 2 2 4 6 5 1 1 0 5 3 2 6 2 2 1 5 6 6 4 3 5 0 6 3 6 5 1 4 2 1 2 6 1 1 3 0 6 6 5 1 3 1 3 2 2 4 0 6 1 1 6 5 6 5 6 1 3 0 2 3 1 5 3 6 4 3 3 4 4 5 2 6 2 6 0 6 1 2 0 2 6 6 6 1 6 0 4 4 2 6 5 6 0 5 0 5 2 6 1 5 4 3 3 3 4 0 1 2 0 5 0 3 0 0 5 2 6 3 2 6 0 5 0 3 1 5 4 0 0 0 4 4 5 0 4 1 0 4 5 0 3 1 2 3 6 6 1 4

以上總共 2 比測試資料

## OUTPUT FILE
輸出檔 page 替換結果。
* **Example:** 100_lru_out.txt ~ 700_lru_out.txt  

		Number of pages: 100
		Number of frames: 5
		Refernec string: 4 2 1 4 4 3 3 4 2 3 1 1 0 4 4 3 1 4 3 4 3 0 1 5 1 1 1 4 1 1 5 0 3 3 2 3 1 4 6 6 4 0 2 3 3 0 4 2 4 0 4 4 5 1 5 2 6 0 6 3 2 1 0 4 1 6 4 3 3 5 4 2 5 5 6 4 2 2 4 5 6 2 0 2 6 2 4 6 3 3 2 2 4 0 0 4 4 0 6 4 
		4     
		4 2    
		4 2 1   
		4 2 1 4  
		4 2 1 4 4 
		3 2 1 4 4 	occur, Now page fault: 1
		3 2 1 4 4 
		3 2 1 4 4 
		3 2 1 4 4 
		3 2 1 4 4 
		3 2 1 4 4 
		3 2 1 4 4 
		3 2 1 4 0 	occur, Now page fault: 2
		3 2 1 4 0 
		3 2 1 4 0 
		3 2 1 4 0 
		3 2 1 4 0 
		3 2 1 4 0 
		3 2 1 4 0 
		3 2 1 4 0 
		3 2 1 4 0 
		3 2 1 4 0 
		3 2 1 4 0 
		3 5 1 4 0 	occur, Now page fault: 3
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 4 0 
		3 5 1 2 0 	occur, Now page fault: 4
		3 5 1 2 0 
		3 5 1 2 0 
		3 4 1 2 0 	occur, Now page fault: 5
		3 4 1 2 6 	occur, Now page fault: 6
		3 4 1 2 6 
		3 4 1 2 6 
		3 4 1 0 6 	occur, Now page fault: 7
		2 4 1 0 6 	occur, Now page fault: 8
		2 4 3 0 6 	occur, Now page fault: 9
		2 4 3 0 6 
		2 4 3 0 6 
		2 4 3 0 6 
		2 4 3 0 6 
		2 4 3 0 6 
		2 4 3 0 6 
		2 4 3 0 6 
		2 4 3 0 6 
		2 4 3 0 5 	occur, Now page fault: 10
		2 4 1 0 5 	occur, Now page fault: 11
		2 4 1 0 5 
		2 4 1 0 5 
		2 4 1 6 5 	occur, Now page fault: 12
		2 0 1 6 5 	occur, Now page fault: 13
		2 0 1 6 5 
		2 0 3 6 5 	occur, Now page fault: 14
		2 0 3 6 5 
		2 0 3 6 1 	occur, Now page fault: 15
		2 0 3 6 1 
		2 0 3 4 1 	occur, Now page fault: 16
		2 0 3 4 1 
		2 0 6 4 1 	occur, Now page fault: 17
		2 0 6 4 1 
		3 0 6 4 1 	occur, Now page fault: 18
		3 0 6 4 1 
		3 5 6 4 1 	occur, Now page fault: 19
		3 5 6 4 1 
		3 5 6 4 2 	occur, Now page fault: 20
		3 5 6 4 2 
		3 5 6 4 2 
		3 5 6 4 2 
		3 5 6 4 2 
		3 5 6 4 2 
		3 5 6 4 2 
		3 5 6 4 2 
		3 5 6 4 2 
		3 5 6 4 2 
		3 5 6 4 2 
		0 5 6 4 2 	occur, Now page fault: 21
		0 5 6 4 2 
		0 5 6 4 2 
		0 5 6 4 2 
		0 5 6 4 2 
		0 5 6 4 2 
		0 3 6 4 2 	occur, Now page fault: 22
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 
		0 3 6 4 2 

		Total page fault: 22
		Hit: 78   Hit ratio: 0.78
		Miss: 22   Miss ratio: 0.22

		Execution time: 0.11 sec
