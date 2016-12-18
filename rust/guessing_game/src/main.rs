
extern crate rand;

use std::io;
use rand::Rng;
use std::cmp::Ordering;


// We return an empty tuple, not void as in C
fn main() {

    // Macros, uses ! to indicate that fact
    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    //println!("The secret number is {}", secret_number);

    loop {

        println!("Please input your guess.");

        // here is a mutable variable binding
        // String is growable utf8 string
        // new() is associated function for String type
        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            // .ok()
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num, // wtf
            Err(_) => continue,
        };

        println!("You tried {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less    => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal   => { 
                println!("You win!");
                break;
            }
        }
    }

}
