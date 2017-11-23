﻿using Google.Apis.Auth.OAuth2;
using Google.Apis.Gmail.v1;
using Google.Apis.Gmail.v1.Data;
using Google.Apis.Services;
using Google.Apis.Util.Store;
using System;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Caliper.Infakt;
using Excel;
using MimeKit;

namespace GmailQuickstart
{
    class Program
    {
        static void Main(string[] args)
        {
            var zoho = new ZohoSupportClient();

            using (var stream = File.OpenRead(@"E:\Marcin\Clouds\Google Drive\Mediporta\Liderzy\2016-09-07 - Porządkowanie Support.xlsx"))
            using (var excel = ExcelReaderFactory.CreateOpenXmlReader(stream))
            {
                excel.IsFirstRowAsColumnNames = true;
                var dataset = excel.AsDataSet();

                var map = new Dictionary<string, List<int>>();
                var count = 0;

                foreach (DataRow row in dataset.Tables["Pomoc"].Rows)
                {
                    var email = (string)row["E-mail"];

                    if (!(row["Zgłoszenie"] is double))
                        continue;

                    var id = (int)(double)row["Zgłoszenie"];

                    if (!map.ContainsKey(email))
                        map[email] = new List<int>();

                    map[email].Add(id);
                    count++;
                }

                Console.WriteLine(count);

                using (var writer = new StreamWriter("log.txt"))
                    foreach (var email in map.Keys)
                    {
                        var contacts = zoho.Contacts.Search(new ZohoSupportContact { Email = email }, 0, 100);

                        if (contacts.Count != 1)
                        {
                            writer.WriteLine("Count({0}) = {1}", email, contacts.Count);
                        }
                        writer.Flush();
                    }
            }
        }


        // If modifying these scopes, delete your previously saved credentials
        // at ~/.credentials/gmail-dotnet-quickstart.json
        static string[] Scopes = { GmailService.Scope.GmailReadonly };
        static string ApplicationName = "Gmail API .NET Quickstart";

        static void Main2(string[] args)
        {
            UserCredential credential;

            using (var stream = File.OpenRead("client_secret.json"))
            {
                var credPath = Path.Combine("gmail-dotnet-quickstart.json");

                var clientSecrets = GoogleClientSecrets.Load(stream).Secrets;
                var fileDataStore = new FileDataStore(credPath, true);
                credential = GoogleWebAuthorizationBroker.AuthorizeAsync(
                    clientSecrets,
                    Scopes,
                    "user",
                    CancellationToken.None,
                    fileDataStore).Result;
                Console.WriteLine("Credential file saved to: " + credPath);
            }

            // Create Gmail API service.
            var service = new GmailService(new BaseClientService.Initializer()
            {
                HttpClientInitializer = credential,
                ApplicationName = ApplicationName,
            });

            //var labels = service.Users.Labels.List("me").Execute().Labels;

            // Define parameters of request.
            var request = service.Users.Threads.List("me");
            request.LabelIds = "Label_2";

            using (var text = new StreamWriter("output-2.txt"))
            {
                do
                {
                    var result = request.Execute();

                    foreach (var thread in result.Threads)
                    {
                        var messages = service.Users.Threads.Get("me", thread.Id).Execute().Messages;

                        var subjects = messages
                            .Select(m => m.Payload.Headers.SingleOrDefault(h => h.Name == "Subject")?.Value)
                            .Where(s => s != null)
                            .ToList();

                        var autosubject = subjects.FirstOrDefault(s => s.Contains("[##") && s.Contains("##]")) ?? "";

                        if (autosubject == "")
                        {
                            foreach (var subject in subjects.Distinct())
                                Console.WriteLine("--- {0}", subject);
                        }
                        else
                        {
                            var start = autosubject.IndexOf("[##") + 3;
                            autosubject = autosubject.Substring(start, autosubject.IndexOf("##]") - start);
                        }

                        var froms = messages.Select(m => m.Payload.Headers.Single(h => h.Name == "From").Value).Distinct();

                        foreach (var from in froms)
                        {
                            var sender = MailboxAddress.Parse(from);

                            if (sender.Address == "pomoc@mediporta.pl")
                                continue;

                            var output = string.Join("\t", sender.Name, sender.Address, autosubject);

                            Console.WriteLine(output);
                            text.WriteLine(output);
                        }
                    }

                    request.PageToken = result.NextPageToken;
                } while (request.PageToken != null);
            }

        }
    }
}