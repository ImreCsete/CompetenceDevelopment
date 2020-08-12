fn main() {
    println!("Hello, world!");
    another_function();
    another_function2(5);

    let a = sum(10, 5);

    println!("Sum is {}.", a)
}

fn another_function() {
    println!("Hello from function!");
}

fn another_function2(x:i32) {
    println!("Value of x is {}.", x);
}

fn sum(x:i32, y:i32) -> i32 {
    let mut a = x + y;

    a = a * 100;

    return a;
}
