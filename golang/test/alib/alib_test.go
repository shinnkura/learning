package alib

import "testing"

var Debug bool = false

func TestAverage(t *testing.T) {
	if Debug {
		t.Skip("Skip")
	}

	slice := []int{1, 2, 3, 4, 5}
	v := Average(slice)
	if v != 3 {
		t.Errorf("%v != 3", v)
	}
}
