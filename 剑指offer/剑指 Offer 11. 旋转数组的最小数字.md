```c
int minArray(int* numbers, int numbersSize) {
    int l = 0, r = numbersSize - 1, m = -1;

    if (numbersSize == 1) return numbers[0];

    while (l < r)
    {
        m = (l + r) / 2;
        //if (numbers[m] > numbers[r]) l = m + 1;
        if (numbers[m] >= numbers[r])
        {
            int a = minArray(numbers, m - l + 1);

            int b = minArray(&numbers[m+1], r - m);
            return a > b ? b : a;
        }
        else r = m;
    }
    /*
    while (l < r)
    {
        m = (l + r) / 2;
        if (numbers[m] > numbers[r]) l = m + 1;
        else if (numbers[m] == numbers[r]) r --; // important~~
        else r = m;
    }
    */
    return numbers[l];
}
```

