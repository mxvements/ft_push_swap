/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:51:49 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/19 19:51:53 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array using the Fisher-Yates Shuffle algorithm
void fisherYatesShuffle(int arr[], int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to introduce more "noise" by shuffling the array multiple times
void introduceNoise(int arr[], int size, int numShuffles) {
    for (int i = 0; i < numShuffles; ++i) {
        fisherYatesShuffle(arr, size);
    }
}

int main() {
    srand(time(NULL));

    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Create an array of sequential integers from 0 to N-1
    int *uniqueInts = malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        uniqueInts[i] = i;
    }

    // Shuffle the array using Fisher-Yates Shuffle
    fisherYatesShuffle(uniqueInts, N);

    // Introduce more "noise" by shuffling the array multiple times
    int numShuffles = 10; // You can adjust this value based on the desired level of noise
    introduceNoise(uniqueInts, N, numShuffles);

    // Print the shuffled unique random integers
    printf("Randomized Unique Integers: ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", uniqueInts[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(uniqueInts);

    return 0;
}
