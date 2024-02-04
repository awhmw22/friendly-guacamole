using Pharmacy_Management_System.BL;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Pharmacy_Management_System.DL
{
    public class UserDL
    {
        private static List<User> users = new List<User>();
        public static List<User> getUsers()
        {
            return users;
        }
        public static void setUser(User user)
        {
            users.Add(user);
        }
        
        public static List<User> searchUser(string name)
        {
            List<User> users = new List<User> ();
            foreach (User item in UserDL.getUsers())
            {
                if (item.Name == name)
                {
                    users.Add(item);
                }
            }
            if (users.Count!=0)
            {
                return users;
            }
            return null;
        }
        public static User login(string username, string password)
        {
            foreach (User item in UserDL.getUsers())
            {
                if (item.Name == username && item.Password == password)
                {
                    return item;
                }
            }
            return null;
        }
        public static User check(string ID)
        {
            foreach (User item in UserDL.getUsers())
            {
                if (item.Id == ID)
                {
                    return item;
                }
            }
            return null;
        }
        public static User checkByName(string name)
        {
            foreach (User item in UserDL.getUsers())
            {
                if (item.Name == name)
                {
                    return item;
                }
            }
            return null;
        }


        public static bool readFromFile(string filePath)
        {
            StreamReader f = new StreamReader(filePath);
            string record;
            if (File.Exists(filePath))
            {
                while ((record = f.ReadLine()) != null)
                {
                    string[] splittedRecord = record.Split(',');
                    string username = splittedRecord[0];
                    string password = splittedRecord[1];
                    string id = splittedRecord[2];
                    string userType = splittedRecord[3];

                    DateTime dob;
                    if (!DateTime.TryParse(splittedRecord[4], out dob))
                    {
                        // Handle the case where the date string is not in a valid format.
                        // This could be logging an error, skipping this record, etc.
                        continue;
                    }

                    string email = splittedRecord[5];
                    long phone = long.Parse(splittedRecord[6]);
                    User user = new User(userType, username, dob, phone, email, password, id);
                    setUser(user);
                }
                f.Close();
                return true;
            }
            else
            {
                return false;
            }
        }
        public static void storeintoFile(string filePath)
        {
            StreamWriter f = new StreamWriter(filePath);
            foreach (User user in UserDL.getUsers())
            {

            f.WriteLine(user.Name + "," + user.Password + "," + user.Id + "," + user.UserType + "," + user.DOB + "," + user.Email + "," + user.PhoneNo);
            }
            f.Flush();
            f.Close();
            
        }
        public static bool removeUserInList(string usernameOrID)
        {
            foreach (User item in UserDL.getUsers())
            {
                if (item.Id == usernameOrID)
                {
                    UserDL.getUsers().Remove(item);
                    UserDL.storeintoFile(Program.userPath);
                    return true;
                }
            }
            return false;
        }
        // Check Email Format......................................................
        public static bool checkEmail(string email)
        {
            char[] Mail = { '@', 'g', 'm', 'a', 'i', 'l', '.', 'c', 'o', 'm' };
            int lengthOfEmail = email.Length - 11;
            int countEmail = email.Length - 1;

            int i = 9;
            bool flag = false;
            while (countEmail != lengthOfEmail)
            {
                if (email[countEmail] == Mail[i] || email[0] != '@')
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
                countEmail--;
                i--;
            }
            return flag;
        }
        //Check CNIC for Sign up ........................................

        public static bool checkCNIC(long aCNIC)
        {
            long firstDigit = aCNIC / 1000000000000;
            long cnic = aCNIC, b = 0;
            while (cnic != 0)
            {
                cnic = cnic / 10;
                b++;
                if (cnic == 0)
                {
                    if (b != 13 && firstDigit != 3)
                    {

                        return false;
                    }
                    else if (b == 13 && firstDigit == 3)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    }
}
