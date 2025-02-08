package alib

func Average(s []int) int {
	sum := 0
	for _, v := range s {
		sum += v
	}
	return sum / len(s)
}
