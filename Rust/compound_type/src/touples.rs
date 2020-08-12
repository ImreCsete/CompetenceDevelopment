fn main() {
    let tup: (i32, f64, u8) = (500, 3.5, 1);

    let (x,y,z) = tup;

    let a = tup.0;
    let b = tup.1;

    println!("x = {}, y = {}, z = {}", x,y,z);

    println!("a = {}, b = {}", a,b);
}
