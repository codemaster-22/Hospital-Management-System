# Hospital-Record
Problem Statement:
- A hospital wants to develop an application to maintain the doctor and patient records. The
specifications are as follows: A doctor has a unique ID and a list of patients he/she attends to. A
patient has a unique ID and a corresponding doctor who treats him/her. A doctor can treat a
maximum of P patients and a patient can only be treated by one doctor. Both the doctor and patient
IDs are unique integers. Write a code to implement the above system using two different binary
search trees (BSTs) to store the doctor and patients profiles respectively. Your code must support the
following operations on the BSTs
- Insert a doctor profile: 1 <docID> Print -1 if the docID already exists
- Insert a patient profile: 2 <patientID> <docID>
Print -1 if the patientID already exists or if the doctor has already reached maximum limit or
if the doctor ID doesn’t exist. Note that the changes have to be reflected on doctor BST as
well
- Delete a patient profile: 3 <patientID>
Print -1 if the patientID does not exit. You are expected to always replace the node being
deleted with the rightmost child of its left subtree if it exists. Replace it with the leftmost
child of the right subtree otherwise. Note that the changes need to be reflected in the doctor
profile as well
- Given a docID print the list of his/her patients in the increasing order of their patient IDs :
4 <docID>
Note that this list could be empty
- Given a patientID, print docID of the doctor who treats him/her: 5 <patientID>
- Print all the doctor profiles in preorder: 6
- Print all the patients in preorder: 7
