package main

import (
	"sort"
)

type sortArray [][2]int

func (s sortArray) Less(i, j int) bool {
	return s[i][0] < s[j][0]
}

func (s sortArray) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s sortArray) Len() int {
	return len(s)
}

func advantageCount(A []int, B []int) []int {
	BB := make([][2]int, len(B))
	for i := 0; i < len(BB); i++ {
		BB[i] = [2]int{B[i], i}
	}
	sort.Ints(A)
	sort.Sort(sortArray(BB))

	C := make([]int, len(A))

	bl, br := 0, len(BB)-1
	for i := 0; i < len(A); i++ {
		if A[i] > BB[bl][0] {
			C[BB[bl][1]] = A[i]
			bl++
		} else {
			C[BB[br][1]] = A[i]
			br--
		}
	}

	return C
}
