from selenium.webdriver.common.by import By
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager


driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))

driver.get("https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1606732401/?envType=study-plan-v2&envId=top-interview-150")
meta_description = driver.find_element(By.XPATH, '//meta[@name="description"]')
meta_title = driver.find_element(By.XPATH,'//meta[@property="og:title"]')
description_content = meta_description.get_attribute('content')
title_content = meta_title.get_attribute('content')

print(title_content)