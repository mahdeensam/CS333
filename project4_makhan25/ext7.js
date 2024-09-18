let x = 10;

function outer() {
    let y = 20;

    function inner() {
        let z = 30;
        console.log(x + y + z);
    }

    inner();
    console.log(x + y);
}

outer();
console.log(x);