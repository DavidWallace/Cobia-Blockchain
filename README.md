# Cobia Blockchain

Blockchain solution for enterprise clients

## What is it?

Cobia Blockchain is an enterprise orientated solution aimed a businesses.

### What can it do?

This is a blockchain solution with lots of potential. The type of things this can be used for are:

* Storing Data on a cloud of computers, i.e. no need for a centralised server to store ANY data (data reduncancy required)
* A DBMS System can easliy be built ontop of this
* Online Leaderboard
* Secure Data Storage (Data Encryption)


### Sample Code

This code below will encrypt data, store it on the blockchain however, it is more logical to do it using the command line interface.

```
string testHash = "Hello User";
cout << "Initial test hash of" << testHash << endl;
testHash = randInsert(testHash, 103, 109);
```


## The Future

### Where are we at?

The blockchain works and functions properly with a revolutionary storage mechanism called a blocktrail. This method stores random data around random files on a network in 'micro-blocks'. This is the first blockchain to work the way this does (however was inspired by the Sia blockchain network's principals).

With this, you can have a huge blockchain with lots or redundancy so that you will never lose data on a network even if a node/ host goes offline (because another node will have it)

### Whats next

Right now we have blockchain, no network. This will be extended for this to work across an actual network. This will incorporate redundancy and allow many notes to host on the network.

### 0.1 Known Bugs and Issues

There are likely tonnes of bugs, here are some being fixed:

```
No Spaces Allowed - Input to Blockchain Does Not Accept Spaces on Linux/ Mac ( _ works better )
Special Characters Cause Errors
Encryption Can Be Hacked/ Cracked With A Lot Of Effort (can be more secure)
Messy Code, Needs Better formatting
Maybe Blocktrails should be encrypted too (TBD)
```


## Versioning

* 0.1 Blockchain Launch

## Authors

* **David Wallace** - *Initial work* - [davidwallace](https://github.com/davidwallace)

## License

This project is licensed under the Apache License 2.0 [LICENSE Terms](https://www.apache.org/licenses/LICENSE-2.0).


## Acknowledgments

* Credit to Sergiy Osadchyy for writing an initial Open-Source C++ RSA Encryption Algorithm used in the program (heavily modified)
* Inspired by Bitcoin, Ethereum, IOTA and Sia mostly. All extremely promessing projects, without them this wouldn't exist.


