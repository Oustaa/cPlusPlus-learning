let start = 0n,
  next = 1n,
  temp;

for (let i = 0; i <= 1000; i++) {
  temp = next;
  next += start;

  console.log(`${start} `);
  start = temp;
}

