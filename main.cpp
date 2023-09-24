
#include <iostream>
#include <vector>
#include <chrono>


void Swap_Elements(int& ElementOne,int& ElementTwo)
{
	int Temp = ElementOne;
	ElementOne = ElementTwo;
	ElementTwo = Temp;
}
void Print_Vector(std::vector<int>& VectorToPrint)
{
	for (int print_vector : VectorToPrint)
	{
		std::cout << print_vector << " | ";
	}
}
void Heapify(std::vector<int>& VectorToSort, int Max, int Index)
{
	int Largest = Index;
	int LeftNode = 2 * Index + 1;
	int RightNode = 2 * Index + 2;

	if (LeftNode<Max && VectorToSort[LeftNode]>VectorToSort[Largest])
		Largest = LeftNode;
	if (RightNode<Max && VectorToSort[RightNode]>VectorToSort[Largest])
		Largest = RightNode;
	if (Largest!=Index)
	{
		Swap_Elements(VectorToSort[Index], VectorToSort[Largest]);
		Heapify(VectorToSort, Max, Largest);
	}

}

void HeapSort(std::vector<int>& VectorToSort)
{
    int Max = VectorToSort.size();

    for (int i = Max / 2 - 1; i >= 0; i--)
        Heapify(VectorToSort, Max, i);

	for (int j = Max - 1; j > 0; j--) {
		Swap_Elements(VectorToSort[0], VectorToSort[j]);
		Heapify(VectorToSort, j, 0);
	}
}

std::vector<int> BubbleSort(std::vector<int>& VectorToSort)
{
		bool isSwapped;
		for (int i = 0; i<VectorToSort.size();i++)
		{
			isSwapped = false;
			for (int n = 0; n < VectorToSort.size()-1; n++)
			{
				if (VectorToSort[n] > VectorToSort[n+1])
				{
					std::swap(VectorToSort[n], VectorToSort[n+1]);
					isSwapped = true;
				}
			}
			if(!isSwapped)
				break;
			
		}
	return VectorToSort;
}

int Divide(std::vector<int>& VectortoSort, int LeftMost, int RightMost)
{
	int Pivot = VectortoSort[RightMost];
	int i = LeftMost;
	for(int j = LeftMost;j<=RightMost -1;j++)
		if(VectortoSort[j]<Pivot)
		{
			Swap_Elements(VectortoSort[i], VectortoSort[j]);
			i++;
		}

	Swap_Elements(VectortoSort[i], VectortoSort[RightMost]);
	return i;
}

void QuickSort(std::vector<int>& VectortoSort,int LeftMost, int RightMost)
{
	if (RightMost <= LeftMost) return;

	int Pivot = Divide(VectortoSort, LeftMost, RightMost);

	QuickSort(VectortoSort, LeftMost, Pivot - 1);
	QuickSort(VectortoSort, Pivot + 1, RightMost);
}

int main()
{
	while(true)
	{
		std::vector<int> QuickVector;
		std::vector<int> BubbleVector;
		std::vector<int> HeapVector;

		int AmountOfNumbers = 100000;
		std::cout << "Random Numbers to generate: ";
		std::cin >> AmountOfNumbers;
		std::srand(std::time(nullptr));

		for (int i = 0; i < AmountOfNumbers; i++)
		{
			int RandomNumber = rand() % 10000;
			BubbleVector.push_back(RandomNumber);
			QuickVector.push_back(RandomNumber);
			HeapVector.push_back(RandomNumber);
		}

		auto startQuick = std::chrono::high_resolution_clock::now();
		QuickSort(QuickVector, 0, AmountOfNumbers - 1);
		auto endQuick = std::chrono::high_resolution_clock::now();

		auto startBubble = std::chrono::high_resolution_clock::now();
		BubbleSort(BubbleVector);
		auto endBubble = std::chrono::high_resolution_clock::now();

		auto startHeap = std::chrono::high_resolution_clock::now();
		HeapSort(HeapVector);
		auto endHeap = std::chrono::high_resolution_clock::now();

		Print_Vector(QuickVector);
		std::cout << "Quick Sort" << "\n" << "\n";
		Print_Vector(BubbleVector);
		std::cout << "Bubble Sort" << "\n" << "\n";
		Print_Vector(HeapVector);
		std::cout << "Heap Sort" << "\n" << "\n";

		std::cout << "Quick Sort Time : " << std::chrono::duration_cast<std::chrono::milliseconds>((endQuick)-(startQuick)).count() << " ms" << "\n";
		std::cout << "Bubble Sort Time : " << std::chrono::duration_cast<std::chrono::milliseconds>((endBubble)-(startBubble)).count() << " ms" << "\n";
		std::cout << "Heap Sort Time : " << std::chrono::duration_cast<std::chrono::milliseconds>((endHeap)-(startHeap)).count() << " ms" << "\n";

		int Again = 0;
		std::cout << "Again? Type 1" << std::endl;
		std::cin >> Again;
		if (Again == 1)
		{
			std::cout << "\033c";
			continue;
		}
		else
			break;
	}

}
