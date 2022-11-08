# Flags in Zip

## Description
```
My friend Godam send me a ZIP file, he said got a secret message inside.. Can you help me to find out the secret he is hiding?
```
## Attachment
- [chall.zip](chall.zip)

As you can see, we are given a ZIP file. You need password when unzipping:

```
unzip chall.zip
Archive:  chall.zip
   creating: flag/
[chall.zip] flag/flaG.jpg password:
```

You can use `john` to crack the password `imsohandsome`, but actually all the images are red herring, all are just distraction:

![image](image.png)

## Challenge source

Actually I'm referring a challenge from TJCTF 2022 **sneaker-zipper**, because I think it is interesting to hide data inside a ZIP file

I just refer the [challenge repo of the TJCTF 2022](https://github.com/TJCSec/tjctf-2022-challenges) which is open source

I put the images into `flag` directory and zip it into `chall.zip`, then run the following python script
```py
from zipfile import ZipFile, ZIP_DEFLATED

flag = b"SKR{H1dd3n_S3cr375_1N_D1r3c70rY}"

with ZipFile('chall.zip','w') as zf:
  zf.writestr('flag/', flag, ZIP_DEFLATED)
```

## Solving

There are many ways to solve this, you can refer [my writeup for sneaker-zipper](https://hong5489.github.io/2022-05-16-tjctf2022/#zipper)

The shortest solution to solve this, is to run the command: `unzip -p chall.zip`, the `-p` flag means to extract files to pipe

```bash
unzip -p chall.zip
# SKR{H1dd3n_S3cr375_1N_D1r3c70rY}
```
More complex solution is to copy the data from hexeditor and deflate the data (Can refer my writeup)

## Unintended solution

- [Writeup by Tzion](Flags_In_Zip_Writeup.pdf), solve using FTK Imager