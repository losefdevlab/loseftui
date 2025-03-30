# Losef's Text-based User Interface(Loseftui)

> 版权文本声明:
> Copyright (C) 2025 LosefDevLab
> Copyright (C) 2018-Now XYLCS/XIT
> 主要开发:Along Losef
>
> 以上统称为Loseftui开发团队
>
> Losef's Text-based User Interface (2025)  by Loseftui开发团队 freedom-create in XFCSTD2.
>
> XFCSTD2路径:/XFCSTD2.md

## 概述

> [!NOTE]
>
> 我们可不是什么UI环境,  只是程序!

Losef's Text-based User Interface(Loseftui，后面简称lui)是一个主要面向于GNU/Linux上的基于文本的用户界面。

> [!TIP]
>
> 当然，你也可以用于Windows上，只要你闲着没事干
>
> 但我只能说，你闲透了，还有用文件管理器的时候，没法切磁盘你就老实了

不同于KDE这一类的UI环境，lui的UI界面由纯文本构建而成，这适用于那种...电脑很拉的装不起GUI，或者SSH管理服务器（别在你的服务器本地运行这个玩意，必须使用ssh，否则后果自负，至于什么后果，我想应该是被管理服务器的人骂一顿）的情景，他们不能使用GUI，而必须要依靠TUI，但是现在好像没什么这一方面的TUI。

所以我们制作了这一个lui。

我们将保证，至少能像kde一样，提供桌面环境但是文本构建而成，并且用户使用体验良好，性能与占用也良好，保证低配机能使用。

## 如何一步编译？

确保你有`clang++`（>=14）;  `libc++`(>=11);  `make`;  `git`;  `bash`.

`sh build.sh`

照上面的命令操作,  您就可以只需一个步骤编译lui。

## 贡献&Git规范标准

CMTMSG规范

- 需要先创建当前要做的内容的计划issues, 这个issues可以是需要修复的、更新计划、功能添加(类似于JIRA工单)
- 当做完这些内容/做了新内容的其中一部分/修改新内容的部分/修复一些bug/合并, 按情况分别提交cmtmsg:
  - Add for #x : xxxxxxx
  - Add part for #x : xxxxxxx
  - Update for #x : xxxxxxx
  - Fix in #x : xxxxxxx
  - Merge branch xx(branchname) to xx(branch) in #x : xxxxxx

Release & tag信息规范

- 请使用WVPB版本号规则
- tag无需标注
- Release标题为版本号
- Release描述需用MD格式
- Release描述需按照以下格式进行编写:

  ```
  本次更新:
  -----
  - (本次阶段的所有CMTMSG)
  ```
