use std::io;

fn main() {
    let mut input_check = false;
    let mut input = String::new();

    println!("Please enter a number:");

    match io::stdin().read_line(&mut input) {

        Ok(_) => {
            let test = input.trim().parse::<i32>();

            match test {
                Ok(ok) => {
                    println!("The number is {}.", ok);
                    input_check = true;
                }
                Err(e) => println!("You did not enter a number ({}).", e)
            };
        },
        Err(e) => println!("Input error: {}", e),
    }

    if input_check == true {

        let num:i32 = input.trim().parse().unwrap();

            if num < 10 {
                println!("{} is less than 10.", num);
            } else {
                println!("{} is greater than 10", num);
            }

            if num % 4 == 0 {
                println!("{} is divisible by 4.", num);
            } else if num % 3 == 0 {
                println!("{} is divisible by 3.", num);
            } else if num % 2 == 0 {
                println!("{} is divisible by 2.", num);
            } else {
                println!("{} is not divisible by 4, 3 or 2.", num)
            }
    }
}
