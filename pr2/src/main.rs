
// 4. Згенерувати 1000 випадкових чисел (діапазон 0-100), відфільтрувати усі
// елементи, що більші за середнє значення масиву.

use rand::prelude::*;
use std::time::Instant;

const RANGE_LENGTH: u32 = 1000;
const START_RANGE: i32 = 0;
const END_RANGE: i32 = 100;

const NUM_OF_ALGHORITMS_TO_MEASURE_TIME_AND_MEMORY: u32 = 1_000_000;

fn variant4() {
    let mut rng = rand::rng();

    let mut arr = vec![];
    for _i in 0..RANGE_LENGTH {
        let random_number = rng.random_range(START_RANGE..END_RANGE+1);
        arr.push(random_number);
    }

    let mut sum = 0;
    for i in 0..arr.len() {
        sum = sum + arr[i];
    }

    let average = (sum as f32 / arr.len() as f32) as i32;

    let mut filtered = vec![];
    for i in 0..RANGE_LENGTH {
        if arr[i as usize] > average {
            filtered.push(arr[i as usize]);
        }
    }
    
    // println!("\nBefore filtering:\n{:?}\n", arr);
    // println!("\nAfter filtering:\n{:?}\n", filtered);
}

fn main() {
    let start = Instant::now();

    for _i in 0..NUM_OF_ALGHORITMS_TO_MEASURE_TIME_AND_MEMORY {
        variant4();
    }

   let elapsed = start.elapsed(); 
   println!("Time: {:?}", elapsed);
}



