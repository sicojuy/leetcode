package main

import (
	"fmt"
	"sort"
	"strconv"
)

type sortRunes []rune

func (s sortRunes) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortRunes) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s sortRunes) Len() int {
	return len(s)
}

func SortString(s string) string {
	r := []rune(s)
	sort.Sort(sortRunes(r))
	return string(r)
}

func reorderedPowerOf2(N int) bool {
	var x int
	m := map[string]int{}
	for x = 1; x < 1000000000; x = x << 1 {
		s := strconv.Itoa(x)
		m[SortString(s)] = 1
	}
	s := strconv.Itoa(N)
	if _, ok := m[SortString(s)]; ok {
		return true
	} else {
		return false
	}
}

func main() {
	fmt.Println(reorderedPowerOf2(218))
}
