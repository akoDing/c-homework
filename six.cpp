static void Main(string[] args)
        {
            //MinToMax mtm = new MinToMax();
            int[] array = { 6, 234, 123, 143, 1368, 2, 86 };
            int n = 7;


            for (int i = 0; i < array.Length; i++)
            {
            // 第一层循环



                IList<int> IDs = new List<int>();  // 新建一个


                if (i == 0)
                {
                    IDs = array;
                }
                else
                {
                    IDs = array.Skip(i).Take(n - i*2).ToList<int>(); //新的数据范围
                }

                // 数据长度小于等于1时候直接跳出程序
                if (IDs.Count <= 1)
                {
                    break; 
                }




                int valmin = array[i];
                int minval = IDs.Min();


                for (int j = 0; j < IDs.Count; j++)
                {

                    if (IDs[j] == minval)
                    {
                        array[j+i] = valmin;
                        array[i] = minval;
                        break;
                    }

                }


                if (i == 0)
                {

                    IDs = array;
                }

                else
                {

                    IDs = array.Skip(i).Take(n - i*2).ToList<int>();

                }


                int valmax = array[n - 1- i];
                int maxval = IDs.Max();

                for (int j = 0; j < IDs.Count; j++)
                {
                     if (IDs[j] == maxval)
                    {
                        array[j+i] = valmax;
                        array[n - i - 1] = maxval;
                        break;
                    }
                }



                for (int t = 0; t < array.Length; t++)
                {
                    System.Console.Write(array[t] + "<");
                   
                }
                System.Console.WriteLine();







            }


          
            System.Console.ReadLine();




        }
