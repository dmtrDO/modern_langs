
# 4. Згенерувати 1000 випадкових чисел (діапазон 0-100), 
# відфільтрувати усі елементи, що більші за середнє значення масиву.

const NUM_OF_ALGORITHMS = 10_000

const START_RANGE = 0
const END_RANGE = 100
const NUM_OF_NUMBERS = 1000

function run_algorithm()
    arr = rand(START_RANGE:END_RANGE, NUM_OF_NUMBERS)

    sorted_arr = []
    avg_value = sum(arr) / length(arr)

    for num in arr
	if num > avg_value
	    push!(sorted_arr, num)
	end
    end

    return sorted_arr
end

function test()
    for i in 0:NUM_OF_ALGORITHMS
	run_algorithm()
    end
end

println("\nmeasure time and memory for all num of algorithms:")
@time test()

println("\nmeasure time and memory for one algorithm")
@time run_algorithm()


