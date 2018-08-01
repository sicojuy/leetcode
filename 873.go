package main

import (
	"fmt"
	"sort"
)

func div(a, b int) int {
	if a%b > 0 {
		return a/b + 1
	}
	return a / b
}

func minEatingSpeed(piles []int, H int) int {
	sort.Ints(piles)
	l := 0
	r := len(piles)
	m := 0
	x := 0
	for l < r {
		m = (l + r) / 2
		x = m + 1
		for i := m + 1; i < len(piles); i++ {
			x += div(piles[i], piles[m])
			if x > H {
				break
			}
		}
		if x > H {
			l = m + 1
		} else {
			r = m
		}
	}
	if x == H {
		return piles[l]
	}
	if x > H {
		if l == 0 {
			return piles[l]
		}
	}
	fmt.Println(piles[l])
	for k := piles[l]; k <= piles[l+1]; k++ {
		x = l + 1
		for i := l + 1; i < len(piles); i++ {
			x += div(piles[i], k)
			if x > H {
				break
			}
		}
		if x >= H {
			return k
		}
	}
	return 0
}

func main() {
	fmt.Println(minEatingSpeed([]int{3, 6, 7, 11}, 8))
}
